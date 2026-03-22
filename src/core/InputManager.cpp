
#include <core/InputManager.hpp>

const std::unordered_map<Input::Keys, int> InputManager::_keyMap = {
    {Input::Keys::A, GLFW_KEY_A}, {Input::Keys::B, GLFW_KEY_B}, {Input::Keys::C, GLFW_KEY_C}, {Input::Keys::D, GLFW_KEY_D}, {Input::Keys::E, GLFW_KEY_E}, {Input::Keys::F, GLFW_KEY_F}, {Input::Keys::G, GLFW_KEY_G}, {Input::Keys::H, GLFW_KEY_H}, {Input::Keys::I, GLFW_KEY_I}, {Input::Keys::J, GLFW_KEY_J}, {Input::Keys::K, GLFW_KEY_K}, {Input::Keys::L, GLFW_KEY_L}, {Input::Keys::M, GLFW_KEY_M}, {Input::Keys::N, GLFW_KEY_N}, {Input::Keys::O, GLFW_KEY_O}, {Input::Keys::P, GLFW_KEY_P}, {Input::Keys::Q, GLFW_KEY_Q}, {Input::Keys::R, GLFW_KEY_R}, {Input::Keys::S, GLFW_KEY_S}, {Input::Keys::T, GLFW_KEY_T}, {Input::Keys::U, GLFW_KEY_U}, {Input::Keys::V, GLFW_KEY_V}, {Input::Keys::W, GLFW_KEY_W}, {Input::Keys::X, GLFW_KEY_X}, {Input::Keys::Y, GLFW_KEY_Y}, {Input::Keys::Z, GLFW_KEY_Z}, {Input::Keys::Num0, GLFW_KEY_0}, {Input::Keys::Num1, GLFW_KEY_1}, {Input::Keys::Num2, GLFW_KEY_2}, {Input::Keys::Num3, GLFW_KEY_3}, {Input::Keys::Num4, GLFW_KEY_4}, {Input::Keys::Num5, GLFW_KEY_5}, {Input::Keys::Num6, GLFW_KEY_6}, {Input::Keys::Num7, GLFW_KEY_7}, {Input::Keys::Num8, GLFW_KEY_8}, {Input::Keys::Num9, GLFW_KEY_9}, {Input::Keys::Escape, GLFW_KEY_ESCAPE}, {Input::Keys::Tab, GLFW_KEY_TAB}, {Input::Keys::CapsLock, GLFW_KEY_CAPS_LOCK}, {Input::Keys::Shift, GLFW_KEY_LEFT_SHIFT}, {Input::Keys::Control, GLFW_KEY_LEFT_CONTROL}, {Input::Keys::Alt, GLFW_KEY_LEFT_ALT}, {Input::Keys::Space, GLFW_KEY_SPACE}, {Input::Keys::Enter, GLFW_KEY_ENTER}, {Input::Keys::Backspace, GLFW_KEY_BACKSPACE}, {Input::Keys::Left, GLFW_KEY_LEFT}, {Input::Keys::Right, GLFW_KEY_RIGHT}, {Input::Keys::Up, GLFW_KEY_UP}, {Input::Keys::Down, GLFW_KEY_DOWN}, {Input::Keys::Insert, GLFW_KEY_INSERT}, {Input::Keys::Delete, GLFW_KEY_DELETE}, {Input::Keys::Home, GLFW_KEY_HOME}, {Input::Keys::End, GLFW_KEY_END}, {Input::Keys::PageUp, GLFW_KEY_PAGE_UP}, {Input::Keys::PageDown, GLFW_KEY_PAGE_DOWN}, {Input::Keys::F1, GLFW_KEY_F1}, {Input::Keys::F2, GLFW_KEY_F2}, {Input::Keys::F3, GLFW_KEY_F3}, {Input::Keys::F4, GLFW_KEY_F4}, {Input::Keys::F5, GLFW_KEY_F5}, {Input::Keys::F6, GLFW_KEY_F6}, {Input::Keys::F7, GLFW_KEY_F7}, {Input::Keys::F8, GLFW_KEY_F8}, {Input::Keys::F9, GLFW_KEY_F9}, {Input::Keys::F10, GLFW_KEY_F10}, {Input::Keys::F11, GLFW_KEY_F11}, {Input::Keys::F12, GLFW_KEY_F12}};

const std::unordered_map<Input::MouseButtons, int> InputManager::_buttonMap = {
    {Input::MouseButtons::Left, GLFW_MOUSE_BUTTON_LEFT},
    {Input::MouseButtons::Right, GLFW_MOUSE_BUTTON_RIGHT},
    {Input::MouseButtons::Middle, GLFW_MOUSE_BUTTON_MIDDLE},
    {Input::MouseButtons::Button4, GLFW_MOUSE_BUTTON_4},
    {Input::MouseButtons::Button5, GLFW_MOUSE_BUTTON_5}};

InputManager::InputManager()
    : _windowContext(nullptr), _logger(Logger::GetInstance())
{
    _logger.Log("InputManager initialized", LogLevel::INFO);
}

InputManager::~InputManager()
{
    _logger.Log("InputManager destroyed", LogLevel::INFO);
}

InputManager &InputManager::GetInstance()
{
    Logger::GetInstance().Log("InputManager instance requested", LogLevel::DEBUG);
    static InputManager instance;
    return instance;
}

void InputManager::SetWindowContext(GLFWwindow *context)
{
    _windowContext = context;
    _logger.Log("Window context set", LogLevel::INFO);
}

bool InputManager::IsKeyPressed(Input::Keys key) const
{
    if (!_windowContext)
        return false;

    std::unordered_map<Input::Keys, int>::const_iterator it = _keyMap.find(key);
    if (it == _keyMap.end())
        return false;

    GLFWwindow *window = _windowContext;
    return glfwGetKey(window, it->second) == GLFW_PRESS;
}

bool InputManager::IsKeyReleased(Input::Keys key) const
{
    if (!_windowContext)
        return false;

    std::unordered_map<Input::Keys, int>::const_iterator it = _keyMap.find(key);
    if (it == _keyMap.end())
        return false;

    GLFWwindow *window = _windowContext;
    return glfwGetKey(window, it->second) == GLFW_RELEASE;
}

bool InputManager::IsMouseButtonPressed(Input::MouseButtons button) const
{
    if (!_windowContext)
        return false;

    const std::unordered_map<Input::MouseButtons, int>::const_iterator it = _buttonMap.find(button);

    if (it == _buttonMap.end())
        return false;

    GLFWwindow *window = _windowContext;
    return glfwGetMouseButton(window, it->second) == GLFW_PRESS;
}

bool InputManager::IsMouseButtonReleased(Input::MouseButtons button) const
{
    if (!_windowContext)
        return false;

    const std::unordered_map<Input::MouseButtons, int>::const_iterator it = _buttonMap.find(button);

    if (it == _buttonMap.end())
        return false;

    GLFWwindow *window = _windowContext;
    return glfwGetMouseButton(window, it->second) == GLFW_RELEASE;
}

MousePosition InputManager::GetMousePosition() const
{
    MousePosition pos{0.0, 0.0};
    if (!_windowContext)
        return pos;

    GLFWwindow *window = _windowContext;
    double x, y;
    glfwGetCursorPos(window, &x, &y);
    pos.x = x;
    pos.y = y;
    return pos;
}