#pragma once

#include <memory>

#include "Window.hpp"

namespace MyGame {

class Game {
   public:
    Game();
    ~Game();

    void Run();
    void OnEvent(Event& e);

   private:
    std::unique_ptr<Window> m_window;
    bool m_IsRunning = true;
};

}  // namespace MyGame
