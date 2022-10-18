#include "Game.hpp"

#include <iostream>

namespace MyGame {

// TEMP: Only for test
Point Game::s_point;
Line Game::s_line;
Circle Game::s_circle;

Game::Game() {
    // Create window
    m_window = std::unique_ptr<Window>(
        Window::Create(WindowProps{"MyGame", 800, 600}));

    // Set Game::OnEvent method to be window callback function
    m_window->SetEventCallbackFunc(
        std::bind(&Game::OnEvent, this, std::placeholders::_1));
}

Game::~Game() {}

void Game::Run() {
    // Set up things on screen
    s_point.MoveTo(400, 300);
    s_line.MoveTo(Point(400, 300), Point(0, 0));
    s_circle.MoveTo(400, 300);
    s_circle.SetRadius(20);

    // TEMP: Only for test
    int rgbColor[3] = {255, 0, 0};
    int incColor = 1, decColor = 0;
    int i = 0;
    while (m_IsRunning) {
        // Calculate new background color
        rgbColor[decColor] -= 1;
        rgbColor[incColor] += 1;
        i += 1;
        if (i >= 255) {
            i = 0;
            decColor += 1;
            if (decColor >= 3) {
                decColor = 0;
            }
            incColor = decColor == 2 ? 0 : decColor + 1;
        }

        // Set calculated color
        glClearColor((float)rgbColor[0] / 255.0f, (float)rgbColor[1] / 255.0f,
                     (float)rgbColor[2] / 255.0f, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();

        // Draw on screen
        s_line.Show(1.0f, 0.0f, 0.0f);
        s_point.Show(0.0f, 1.0f, 0.0f);
        s_circle.Show(0.2f, 0.2f, 1.0f);

        m_window->OnUpdate();
    }
}

void Game::OnEvent(Event& e) {
    // Print name of event
    std::cout << e.GetNameToString() << std::endl;

    // Handle WindowCloseEvent
    if (e.GetEventType() == EventType::WindowClose) {
        m_IsRunning = false;
    }
}

}  // namespace MyGame
