#include <tools/Logger.hpp>
#include <core/OpenGLContext.hpp>
#include <exception>

int main()
{
    Logger& logger = Logger::GetInstance();
    try 
    {
        OpenGLContext context(800, 600, "University Thesis");
        GLFWwindow* window = context.GetWindow();

        while (!glfwWindowShouldClose(window))
        {
            if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
                glfwSetWindowShouldClose(window, true);

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }
    catch (const std::exception& e) 
    {
        logger.Log(e.what(), LogLevel::ERROR);
        return -1;
    }
    
    return 0;
}
