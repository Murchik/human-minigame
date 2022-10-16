#pragma once

#include <memory>

#include "GLFW/glfw3.h"
#include "Window.hpp"

namespace MyGame {

class Game {
   public:
    Game();
    ~Game();

    void Run();

   private:
    std::unique_ptr<Window> m_window;
    bool m_IsRunning = true;
};

}  // namespace MyGame
