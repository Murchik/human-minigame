#include "Game.hpp"

#include "GLFW/glfw3.h"

namespace MyGame {

Game::Game() {}

Game::~Game() {}

void Game::run() {
    while (true) {
        m_window.OnUpdate();
    }
}

}  // namespace MyGame
