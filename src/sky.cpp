#include "sky.h"
#include "console_utils.h"

Sky::Sky() {
    sky = {
        "                                                  ",
        "   .--.      .--.                                  ",
        "  '    `    '    `                                 ",
        "   (    )    (    )                                ",
        "    `--'      `--'                                 ",
        "                                                  "
    };
}

void Sky::draw() {
    setColor(CYAN);
    for (int y = 0; y < sky.size(); ++y) {
        gotoxy(0, y);
        std::cout << sky[y];
    }
}