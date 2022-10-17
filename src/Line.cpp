#include "shapes/Line.hpp"

#include "GLFW/glfw3.h"

void Line::SetStart(int x, int y) {
    m_start.SetX(x);
    m_start.SetY(y);
}

void Line::SetStart(const Point &p) {
    m_start.SetX(p.GetX());
    m_start.SetY(p.GetY());
}

void Line::SetEnd(int x, int y) {
    m_end.SetX(x);
    m_end.SetY(y);
}

void Line::SetEnd(const Point &p) {
    m_end.SetX(p.GetX());
    m_end.SetY(p.GetY());
}

int Line::GetStartX() { return m_start.GetX(); }

int Line::GetStartY() { return m_start.GetY(); }

int Line::GetEndX() { return m_end.GetX(); }

int Line::GetEndY() { return m_end.GetY(); }

void Line::Show(float r, float g, float b) {
    glBegin(GL_LINES);
    glColor3f(r, g, b);
    glVertex2i(m_start.GetX(), m_start.GetY());
    glVertex2i(m_end.GetX(), m_end.GetY());
    glEnd();
}

void Line::MoveTo(const Point &newStart, const Point &newEnd) {
    SetStart(newStart);
    SetEnd(newEnd);
}

void Line::MoveTo(int newStartX, int newStartY, int newEndX, int newEndY) {
    SetStart(newStartX, newStartY);
    SetEnd(newEndX, newEndY);
}

// bool Line::intersects(Line &line) {}
// bool Line::intersects(Circle &circle) {}
