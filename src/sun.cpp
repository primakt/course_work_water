#include "sun.h"
#include "console_utils.h"

void Sun::draw() {
    setColor(YELLOW);
    gotoxy(70, 0); std::cout << " \\ / ";
    gotoxy(70, 1); std::cout << "  O  ";
    gotoxy(70, 2); std::cout << " / \\ ";
    setColor(WHITE);
}