#pragma once
#include "drawable.h"
#include <vector>
#include <string>

class Sky : public Drawable {
public:
    Sky();
    void draw() override;
    void update() override {}
private:
    std::vector<std::string> sky;
};