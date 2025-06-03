#include "forest.h"
#include "console_utils.h"
#include <cstdlib>

Forest::Forest() {
    forest.resize(13, std::string(80, ' '));
    const std::string TREE = "(Y)";
    for (int y = 0; y < forest.size(); ++y) {
        for (int x = 0; x < 80; ++x) {
            if ((rand() % 100) < 7 && x + TREE.size() <= 80) {
                forest[y].replace(x, TREE.size(), TREE);
            }
        }
    }
    forest.back().assign(80, '=');
}

void Forest::draw() {
    setColor(GREEN);
    for (int y = 0; y < forest.size(); ++y) {
        gotoxy(0, 12 + y);
        std::cout << forest[y];
    }
}