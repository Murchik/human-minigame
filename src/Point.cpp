#include "shapes/Point.hpp"

#include "GLFW/glfw3.h"

void Point::Show(float r, float g, float b) {
    glBegin(GL_POINTS);
    glColor3f(r, g, b);
    glVertex2i(GetX(), GetY());
    glEnd();
}

void Point::MoveTo(int x, int y) {
    SetX(x);
    SetY(y);
}
