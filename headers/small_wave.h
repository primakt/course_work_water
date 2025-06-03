#pragma once
#include "wave.h"
#include <string>

class SmallWave : public Wave {
public:
    SmallWave(int x, int y);
    void draw() override;
    void update() override;
private:
    int frameCounter = 0;
    const std::string pattern = "-=-.";
};