#pragma once

#include <tools/Logger.hpp>
#include <GLFW/glfw3.h>
#include <unordered_map>

struct Input
{
    enum class Keys
    {
        Unknown = -1,
        A,
        B,
        C,
        D,
        E,
        F,
        G,
        H,
        I,
        J,
        K,
        L,
        M,
        N,
        O,
        P,
        Q,
        R,
        S,
        T,
        U,
        V,
        W,
        X,
        Y,
        Z,
        Num0,
        Num1,
        Num2,
        Num3,
        Num4,
        Num5,
        Num6,
        Num7,
        Num8,
        Num9,
        Escape,
        Tab,
        CapsLock,
        Shift,
        Control,
        Alt,
        Space,
        Enter,
        Backspace,
        Left,
        Right,
        Up,
        Down,
        Insert,
        Delete,
        Home,
        End,
        PageUp,
        PageDown,
        F1,
        F2,
        F3,
        F4,
        F5,
        F6,
        F7,
        F8,
        F9,
        F10,
        F11,
        F12
    };

    enum class MouseButtons
    {
        Unknown = -1,
        Left,
        Right,
        Middle,
        Button4,
        Button5
    };
};

struct MousePosition
{
    double x;
    double y;
};

class InputManager
{
    public:
        ~InputManager();

        InputManager(const InputManager &) = delete;
        InputManager &operator=(const InputManager &) = delete;
        InputManager(InputManager &&) = delete;
        InputManager &operator=(InputManager &&) = delete;

        static InputManager &GetInstance();
        void SetWindowContext(GLFWwindow* context);

        bool IsKeyPressed(Input::Keys key) const;
        bool IsKeyReleased(Input::Keys key) const;
        bool IsMouseButtonPressed(Input::MouseButtons button) const;
        bool IsMouseButtonReleased(Input::MouseButtons button) const;
        MousePosition GetMousePosition() const;

    private:
        static const std::unordered_map<Input::Keys, int> _keyMap;
        static const std::unordered_map<Input::MouseButtons, int> _buttonMap;

        GLFWwindow* _windowContext;
        Logger& _logger;

        InputManager();

};