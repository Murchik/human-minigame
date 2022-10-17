#pragma once

#include <memory>

#include "Window.hpp"
#include "shapes/Circle.hpp"
#include "shapes/Line.hpp"
#include "shapes/Point.hpp"

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
    static Point s_point;
    static Line s_line;
    static Circle s_circle;
};

}  // namespace MyGame
