#pragma once
#include "drawable.h"
#include <vector>
#include <string>

class Forest : public Drawable {
public:
    Forest();
    void draw() override;
    void update() override {}
private:
    std::vector<std::string> forest;
};