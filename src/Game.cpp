#include "Game.hpp"

#include "GLFW/glfw3.h"

namespace MyGame {

Game::Game() {
    m_window = std::unique_ptr<Window>(
        Window::Create(WindowProps{"MyGame", 800, 600}));
}

Game::~Game() {}

void Game::Run() {
    int rgbColor[3] = {255, 0, 0};
    int incColor = 1, decColor = 0;
    int i = 0;
    while (m_IsRunning) {
        rgbColor[decColor] -= 1;
        rgbColor[incColor] += 1;
        i += 1;
        if (i >= 255) {
            i = 0;
            decColor += 1;
            incColor = decColor == 2 ? 0 : decColor + 1;
            if (decColor >= 3) {
                decColor = 0;
            }
        }

        glClearColor(rgbColor[0] / 255.0f, rgbColor[1] / 255.0f,
                     rgbColor[2] / 255.0f, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        m_window->OnUpdate();
    }
}

}  // namespace MyGame
