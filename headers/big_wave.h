#pragma once
#include "wave.h"
#include <string>

class BigWave : public Wave {
public:
    BigWave(int x, int y, std::string pattern);
    void draw() override;
    void update() override;
private:
    std::string pattern;
};