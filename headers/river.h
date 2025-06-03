#pragma once
#include "drawable.h"
#include "subject.h"
#include "wave_factory.h"
#include <memory>
#include <vector>

class River : public Drawable, public Subject {
public:
    River();
    void draw() override;
    void update() override;
private:
    std::vector<std::unique_ptr<Wave>> smallWaves;
    std::vector<std::unique_ptr<Wave>> bigWaves;
    std::unique_ptr<WaveFactory> smallWaveFactory;
    std::unique_ptr<WaveFactory> bigWaveFactory;
};