#include "shapes/Circle.hpp"

#include <cmath>

#include "GLFW/glfw3.h"

#ifndef M_PI
#define M_PI 3.141592653589793f
#endif  // !M_PI

void Circle::SetRadius(int newRadius) { m_radius = newRadius; }

int Circle::GetRadius() const { return m_radius; }

void Circle::Show(float r, float g, float b) {
    int amountSegments = 360;
    int i;
    float angle;
    float dx, dy;

    glBegin(GL_LINE_LOOP);
    glColor3f(r, g, b);
    for (i = 0; i < amountSegments; i++) {
        angle = 2.0f * M_PI * (float)i / (float)amountSegments;

        dx = (float)GetRadius() * cosf(angle);
        dy = (float)GetRadius() * sinf(angle);

        glVertex2f((float)GetX() + dx, (float)GetY() + dy);
    }
    glEnd();
}
