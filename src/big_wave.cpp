#include "big_wave.h"
#include "console_utils.h"

BigWave::BigWave(int x, int y, std::string pattern) : Wave(x, y), pattern(std::move(pattern)) {}

void BigWave::draw() {
    if (y >= 0 && y < HEIGHT) {
        gotoxy(x, y);
        std::cout << pattern;
    }
}

void BigWave::update() {
    x++;
}