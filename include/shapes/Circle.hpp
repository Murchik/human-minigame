#pragma once

#include "shapes/Point.hpp"

class Circle : public Point {
   public:
    Circle(int x = 0, int y = 0, int radius = 2) : Point(x, y) {
        m_radius = radius;
    }
    virtual ~Circle() {}

    void SetRadius(int radius);
    int GetRadius() const;

    virtual void Show(float r = 1.0f, float g = 1.0f, float b = 1.0f);

    // bool intersects(Line &line);
    // bool intersects(Circle &circle);

   protected:
    int m_radius;
};
