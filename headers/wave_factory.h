#pragma once
#include <memory>
#include "wave.h"

class WaveFactory {
public:
    virtual std::unique_ptr<Wave> createWave(int x, int y) = 0;
    virtual ~WaveFactory() = default;
};