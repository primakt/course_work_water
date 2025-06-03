#include "small_wave_factory.h"
#include "small_wave.h"

std::unique_ptr<Wave> SmallWaveFactory::createWave(int x, int y) {
    return std::unique_ptr<Wave>(new SmallWave(x, y));
}