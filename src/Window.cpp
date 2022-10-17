#include "Window.hpp"

#include <iostream>

#include "GLFW/glfw3.h"
#include "events/WindowEvent.hpp"

namespace MyGame {

Window::Window(const WindowProps& props) {
    // Set window info
    m_Data.Title = props.Title;
    m_Data.Height = props.Height;
    m_Data.Width = props.Width;

    // Init GLFW library
    if (!glfwInit()) {
        std::cout << "Couldn't initialize the GLFW library" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Create window
    m_Window = glfwCreateWindow(m_Data.Width, m_Data.Height,
                                m_Data.Title.c_str(), nullptr, nullptr);
    if (!m_Window) {
        std::cout << "Couldn't create window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // Make the context of the specified window current for the calling thread
    glfwMakeContextCurrent(m_Window);
    SetVSync(true);

    // Set GLFW user pointer to m_Data struct
    glfwSetWindowUserPointer(m_Window, &m_Data);

    // Set GLFW callbacks
    glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* wnd) {
        // Get m_Data from GLFW
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(wnd);

        // Create and dispatch WindowCloseEvent
        WindowCloseEvent event;
        data.EventCallback(event);
    });
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
