#include "sky.h"
#include "console_utils.h"

void Sky::draw() {
    setColor(CYAN);
    for (int y = 0; y < SKY_HEIGHT; ++y) {
        gotoxy(0, y);
        std::cout << sky[y];
    }
}