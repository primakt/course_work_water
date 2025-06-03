#include "small_wave.h"
#include "console_utils.h"

SmallWave::SmallWave(int x, int y) : Wave(x, y) {}

void SmallWave::draw() {
    if (y >= 0 && y < 25) {
        gotoxy(x, y);
        std::cout << pattern[(frameCounter++) % pattern.size()];
    }
}

void SmallWave::update() {
    x++;
}