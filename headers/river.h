#pragma once
#include "drawable.h"
#include "subject.h"
#include <vector>

class River : public Drawable, public Subject {
public:
    River();
    void draw() override;
    void update();
private:
    std::vector<std::pair<int, int>> waves; // Простейшие волны (x, y)
};