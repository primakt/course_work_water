#include "river.h"
#include <cstdlib>
#include <iostream>

River::River() {
    for (int i = 0; i < 5; ++i) {
        waves.emplace_back(rand() % 80, 6); // WIDTH=80, RIVER_HEIGHT=6
    }
}

void River::draw() {
    for (const auto& wave : waves) {
        printf("\033[%d;%dH~", wave.second, wave.first);
    }
}

void River::update() {
    for (auto& wave : waves) {
        wave.first++;
        if (wave.first > 80) wave.first = 0;
    }
    notifyObservers();
}