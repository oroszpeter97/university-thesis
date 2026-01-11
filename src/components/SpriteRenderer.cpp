#include <components/SpriteRenderer.hpp>

#include <core/Shader.hpp>

SpriteRenderer::SpriteRenderer(Transform &transform, Scene *scene, const char *texturePath)
    : _shader("../shaders/default_vertex_shader.glsl", "../shaders/default_fragment_shader.glsl"),
      _scene(scene),
      _transform(transform)
{
    float vertices[] = {
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

        -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f};

    unsigned int VBO;
    glGenVertexArrays(1, &_VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // load texture
    glGenTextures(1, &_texture1);
    glBindTexture(GL_TEXTURE_2D, _texture1);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters (pixel-art: nearest, no mipmaps)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    // load image, create texture (no mipmaps for crisp pixel art)
    int width, height, nrChannels;
    // Do not flip; keep original orientation to match your UVs
    stbi_set_flip_vertically_on_load(false); // was true
    unsigned char *data = stbi_load(texturePath, &width, &height, &nrChannels, 0);
    if (data)
    {
        GLenum format = GL_RGB;
        if (nrChannels == 1)
        {
            format = GL_RED;
        }
        else if (nrChannels == 3)
        {
            format = GL_RGB;
        }
        else if (nrChannels == 4)
        {
            format = GL_RGBA;
        }

        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            format, // internal format matches channels
            width,
            height,
            0,
            format, // data format matches channels
            GL_UNSIGNED_BYTE,
            data);
        // no mipmaps for pixel art
    }
    else
    {
        std::cout << "Failed to load texture: " << texturePath << std::endl;
    }
    stbi_image_free(data);

    _shader.use();
    _shader.setInt("texture1", 0);
}

SpriteRenderer::~SpriteRenderer()
{
}

void SpriteRenderer::OnSetUp()
{
    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::ortho(0.0f, 1280.0f, 0.0f, 720.0f, -1.0f, 100.0f);
    _shader.setMat4("projection", projection);
}

void SpriteRenderer::OnUpdate(float deltaTime)
{
    // enable alpha blending so transparent pixels show correctly
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _texture1);
    _shader.use();

    // create transformations
    glm::mat4 view = glm::mat4(1.0f);
    glm::vec3 viewPosition(640.0f, 360.0f, -20.0f);
    if (_scene)
    {
        Camera *activeCamera = _scene->GetActiveCamera();
        if (activeCamera)
        {
            Transform *cameraTransform =
                activeCamera->GetComponentsByType("Transform").empty()
                    ? nullptr
                    : static_cast<Transform *>(activeCamera->GetComponentsByType("Transform")[0]);
            if (cameraTransform)
            {
                glm::vec3 camPos = cameraTransform->GetPosition();
                viewPosition = glm::vec3(-camPos.x + 640.0f, -camPos.y + 360.0f, -20.0f);
            }
        }
    }
    view = glm::translate(view, viewPosition);
    _shader.setMat4("view", view);

    // render square
    glBindVertexArray(_VAO);
    glm::mat4 model = glm::mat4(1.0f);
    // Center the model and scale it up for visibility
    glm::vec3 centerOffset(640.0f, 360.0f, 0.0f);
    model = glm::translate(model, _transform.GetPosition() + centerOffset);
    model = glm::scale(model, _transform.GetScale() * 32.0f);
    model = glm::rotate(model, glm::radians(_transform.GetRotation().z), glm::vec3(0.0f, 0.0f, 1.0f));
    _shader.setMat4("model", model);

    glDrawArrays(GL_TRIANGLES, 0, 36);
}

std::string SpriteRenderer::GetType() const
{
    return "SpriteRenderer";
}