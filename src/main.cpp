#include <tools/Logger.hpp>
#include <core/OpenGLContext.hpp>

int main()
{
    Logger& logger = Logger::GetInstance();
    GLFWwindow* window = nullptr;
    try 
    {
        OpenGLContext context(800, 600, "University Thesis");
        window = context.GetWindow();
    }
    catch (const std::exception& e) 
    {
        logger.Log(std::string("Exception: ") + e.what(), LogLevel::ERROR);
        return -1;
    }
    

    while(!glfwWindowShouldClose(window))
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    return 0;
}
