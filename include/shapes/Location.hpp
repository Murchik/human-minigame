#pragma once

class Location {
   public:
    Location(int x = 0, int y = 0) : m_X(x), m_Y(y) {}
    ~Location() {}

    void SetX(int x);
    void SetY(int y);
    int GetX() const;
    int GetY() const;

   protected:
    int m_X;
    int m_Y;
};
