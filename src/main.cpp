#include <tools/Logger.hpp>
#include <core/OpenGLContext.hpp>
#include <core/InputManager.hpp>
#include <exception>

int main()
{
    Logger& logger = Logger::GetInstance();
    InputManager& inputManager = InputManager::GetInstance();

    try 
    {
        OpenGLContext context(800, 600, "University Thesis");
        GLFWwindow* window = context.GetWindow();
        inputManager.SetWindowContext(window);

        bool wPressed = false;
        bool leftMousePressed = false;
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
            }
            if (inputManager.IsKeyReleased(Input::Keys::W) && wPressed)
            {
                logger.Log("W key is released", LogLevel::DEBUG);
                wPressed = false;
            }
            if (inputManager.IsMouseButtonPressed(Input::MouseButtons::Left) && !leftMousePressed)
            {
                MousePosition pos = inputManager.GetMousePosition();
                logger.Log("Left mouse button pressed at (" + std::to_string(pos.x) + ", " + std::to_string(pos.y) + ")", LogLevel::DEBUG);
                leftMousePressed = true;
            }
            if (inputManager.IsMouseButtonReleased(Input::MouseButtons::Left) && leftMousePressed)
            {
                MousePosition pos = inputManager.GetMousePosition();
                logger.Log("Left mouse button released at (" + std::to_string(pos.x) + ", " + std::to_string(pos.y) + ")", LogLevel::DEBUG);
                leftMousePressed = false;
            }

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
