#include "sun.h"
#include "console_utils.h"

void Sun::draw() {
    setColor(YELLOW);
    gotoxy(WIDTH - 10, 0); std::cout << " \\ / ";
    gotoxy(WIDTH - 10, 1); std::cout << "  .  ";
    gotoxy(WIDTH - 10, 2); std::cout << " -O- ";
    gotoxy(WIDTH - 10, 3); std::cout << "  '  ";
    gotoxy(WIDTH - 10, 4); std::cout << " / \\ ";
    setColor(WHITE);
}