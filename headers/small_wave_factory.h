#pragma once
#include "wave_factory.h"

class SmallWaveFactory : public WaveFactory {
public:
    std::unique_ptr<Wave> createWave(int x, int y) override;
};