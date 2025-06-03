#pragma once
#include "drawable.h"
#include <utility>

class Wave : public Drawable {
public:
    Wave(int x, int y) : x(x), y(y) {}
    virtual void setPos(int x, int y) { this->x = x; this->y = y; }
    virtual std::pair<int, int> getPos() { return { x, y }; }
protected:
    int x = 0, y = 0;
};