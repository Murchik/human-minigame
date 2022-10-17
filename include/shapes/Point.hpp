#pragma once

#include "shapes/Location.hpp"

class Point : public Location {
   public:
    Point(int x = 0, int y = 0) : Location(x, y) {}
    virtual ~Point() {}

    virtual void Show(float r = 1.0f, float g = 1.0f, float b = 1.0f);
    virtual void MoveTo(int x, int y);
};
