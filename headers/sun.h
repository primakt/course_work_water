#pragma once
#include "drawable.h"

class Sun : public Drawable {
public:
    void draw() override;
    void update() override {}
};