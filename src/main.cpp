#include <tools/Logger.hpp>
#include <core/OpenGLContext.hpp>
#include <core/InputManager.hpp>
#include <core/Transform2D.hpp>
#include <exception>

int main()
{
    Logger &logger = Logger::GetInstance();

    try
    {
        OpenGLContext context(800, 600, "University Thesis");
        GLFWwindow *window = context.GetWindow();
        InputManager &inputManager = InputManager::GetInstance();

        inputManager.SetWindowContext(window);
        Transform2D transform;
        Transform2D transform2 = Transform2D(Vector2D(1, 1), 0.0f, Vector2D(1, 1));

        bool wPressed = false;
        bool sPressed = false;
        bool aPressed = false;
        while (!glfwWindowShouldClose(window))
        {
            if (inputManager.IsKeyPressed(Input::Keys::Escape))
            {
                logger.Log("Escape key pressed, closing window", LogLevel::INFO);
                glfwSetWindowShouldClose(window, true);
            }

            if (inputManager.IsKeyPressed(Input::Keys::W) && !wPressed)
            {
                logger.Log("W key is pressed", LogLevel::DEBUG);
                wPressed = true;

                logger.Log("Transform forward vector: (" + std::to_string(transform.GetForward().X) + ", " + std::to_string(transform.GetForward().Y) + ")", LogLevel::DEBUG);
            }
            if (inputManager.IsKeyReleased(Input::Keys::W) && wPressed)
            {
                logger.Log("W key is released", LogLevel::DEBUG);
                wPressed = false;
            }

            if (inputManager.IsKeyPressed(Input::Keys::S) && !sPressed)
            {
                logger.Log("S key is pressed", LogLevel::DEBUG);
                sPressed = true;

                transform.Rotation += 45.0f; // Rotate 45 degrees when S is pressed
                logger.Log("Transform rotated to: " + std::to_string(transform.Rotation) + " degrees", LogLevel::DEBUG);
            }

            if (inputManager.IsKeyReleased(Input::Keys::S) && sPressed)
            {
                logger.Log("S key is released", LogLevel::DEBUG);
                sPressed = false;
            }

            if (inputManager.IsKeyPressed(Input::Keys::A) && !aPressed)
            {
                logger.Log("A key is pressed", LogLevel::DEBUG);
                aPressed = true;
                
                transform.LookAt(transform2.Position); // Make transform look at transform2's position
                logger.Log("Transform rotated to look at transform2: " + std::to_string(transform.Rotation) + " degrees", LogLevel::DEBUG);
            }

            if (inputManager.IsKeyReleased(Input::Keys::A) && aPressed)
            {
                logger.Log("A key is released", LogLevel::DEBUG);
                aPressed = false;
            }

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }
    catch (const std::exception &e)
    {
        logger.Log(e.what(), LogLevel::ERROR);
        return -1;
    }

    return 0;
}
