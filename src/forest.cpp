#include "forest.h"
#include "console_utils.h"
#include <cstdlib>

Forest::Forest() {
    forest.resize(FOREST_HEIGHT, std::string(WIDTH, ' '));
    const std::string TREE = "(Y)";
    for (int y = 0; y < forest.size(); ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if ((rand() % 100) < 7 && x + TREE.size() <= WIDTH) {
                forest[y].replace(x, TREE.size(), TREE);
            }
        }
    }
    forest.back().assign(WIDTH, '=');
}

void Forest::draw() {
    setColor(GREEN);
    for (int y = 0; y < FOREST_HEIGHT; ++y) {
        gotoxy(0, SKY_HEIGHT + RIVER_HEIGHT + y);
        std::cout << forest[y];
    }
}