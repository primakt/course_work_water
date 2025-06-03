#pragma once
#include "wave_factory.h"

class BigWaveFactory : public WaveFactory {
public:
    std::unique_ptr<Wave> createWave(int x, int y) override;
};