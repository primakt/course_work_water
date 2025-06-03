#include "river.h"
#include "console_utils.h"
#include <cstdlib>

River::River() {
    for (int i = 0; i < 5; ++i) {
        waves.emplace_back(rand() % 80, 6);
    }
}

void River::draw() {
    setColor(BLUE);
    for (int y = 6; y < 12; ++y) {
        gotoxy(0, y);
        std::cout << std::string(80, '~');
    }
    
    setColor(WHITE);
    for (const auto& wave : waves) {
        gotoxy(wave.first, wave.second);
        std::cout << "~";
    }
}

void River::update() {
    for (auto& wave : waves) {
        wave.first++;
        if (wave.first > 80) wave.first = 0;
    }
    notifyObservers();
}