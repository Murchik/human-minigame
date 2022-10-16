#pragma once

#include <string>

#include "GLFW/glfw3.h"

namespace MyGame {

struct WindowProps {
    std::string Title;
    unsigned int Width, Height;

    WindowProps(const std::string& title = "Default window",
                unsigned int width = 1280, unsigned int height = 720)
        : Title(title), Width(width), Height(height) {}
};

class Window {
   public:
    Window(const WindowProps& props);
    ~Window();

    void OnUpdate();

    int GetWidth() { return m_Data.Width; }
    int GetHeight() { return m_Data.Height; }

   private:
    GLFWwindow* m_Window;

    struct WindowData {
        std::string Title;
        unsigned int Width, Height;
    };

    WindowData m_Data;
};

}  // namespace MyGame
