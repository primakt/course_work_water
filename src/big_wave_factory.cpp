#include "big_wave_factory.h"
#include "big_wave.h"
#include <vector>
#include <cstdlib>

std::unique_ptr<Wave> BigWaveFactory::createWave(int x, int y) {
    std::vector<std::string> patterns = { "/\\", "~~/\\", "/\\/\\", "~~~~/\\" };
    return std::unique_ptr<Wave>(new BigWave(x, y, patterns[rand() % patterns.size()]));
}