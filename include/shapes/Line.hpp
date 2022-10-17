#pragma once

#include "shapes/Point.hpp"

class Line {
   public:
    Line(int startX = 0, int startY = 0, int endX = 0, int endY = 0)
        : m_start(startX, startY), m_end(endX, endY) {}
    virtual ~Line() {}

    void SetStart(int x, int y);
    void SetStart(const Point &p);
    void SetEnd(int x, int y);
    void SetEnd(const Point &p);

    int GetStartX();
    int GetStartY();
    int GetEndX();
    int GetEndY();

    void Show(float r = 1.0f, float g = 1.0f, float b = 1.0f);

    void MoveTo(int newStartX, int newStartY, int newEndX, int newEndY);
    void MoveTo(const Point &newStart, const Point &newEnd);

   protected:
    Point m_start;
    Point m_end;
};
