#pragma once

#include "GLFW/glfw3.h"
#include "Window.hpp"

namespace MyGame {

class Game {
   public:
    Game();
    ~Game();

    void run();

   private:
    Window m_window{WindowProps{"Human Game", 960, 720}};
};

}  // namespace MyGame
