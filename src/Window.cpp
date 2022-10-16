#include "Window.hpp"

#include <iostream>

#include "GLFW/glfw3.h"

namespace MyGame {

Window::Window(const WindowProps& props) {
    m_Data.Title = props.Title;
    m_Data.Height = props.Height;
    m_Data.Width = props.Width;

    if (!glfwInit()) {
        std::cout << "Couldn't initialize the GLFW library" << std::endl;
        exit(EXIT_FAILURE);
    }

    m_Window = glfwCreateWindow(m_Data.Width, m_Data.Height,
                                m_Data.Title.c_str(), nullptr, nullptr);
    if (!m_Window) {
        std::cout << "Couldn't create window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(m_Window);
    glfwSetWindowUserPointer(m_Window, &m_Data);
    SetVSync(true);
}

Window::~Window() {
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}

void Window::OnUpdate() {
    glfwPollEvents();
    glfwSwapBuffers(m_Window);
}

void Window::SetVSync(bool isEnabled) {
    if (isEnabled) {
        glfwSwapInterval(1);
    } else {
        glfwSwapInterval(0);
    }
    m_Data.VSync = isEnabled;
}

Window* Window::Create(const WindowProps& props) { return new Window(props); }

}  // namespace MyGame
