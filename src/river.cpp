#include "river.h"
#include "small_wave_factory.h"
#include "big_wave_factory.h"
#include "console_utils.h"
#include <algorithm>
#include <cstdlib>

River::River() : smallWaveFactory(new SmallWaveFactory()),
                bigWaveFactory(new BigWaveFactory()) {
    for (int y = 0; y < RIVER_HEIGHT; ++y) {
        for (int i = 0; i < 5; ++i) {
            auto wave = smallWaveFactory->createWave(rand() % WIDTH, SKY_HEIGHT + y);
            addObserver(wave.get());
            smallWaves.push_back(std::move(wave));
        }
    }
}

void River::draw() {
    setColor(BLUE);
    for (int y = 0; y < RIVER_HEIGHT; ++y) {
        gotoxy(0, SKY_HEIGHT + y);
        std::cout << std::string(WIDTH, '-');
    }

    for (auto& w : smallWaves) {
        w->draw();
    }

    for (auto& w : bigWaves) {
        w->draw();
    }
}

void River::update() {
    if (rand() % 5 == 0) {
        auto wave = smallWaveFactory->createWave(-1, SKY_HEIGHT + rand() % RIVER_HEIGHT);
        addObserver(wave.get());
        smallWaves.push_back(std::move(wave));
    }
    if (rand() % 200 == 0) {
        auto wave = bigWaveFactory->createWave(-5, SKY_HEIGHT + rand() % RIVER_HEIGHT);
        addObserver(wave.get());
        bigWaves.push_back(std::move(wave));
    }
    notifyObservers();

    smallWaves.erase(std::remove_if(smallWaves.begin(), smallWaves.end(),
        [this](const std::unique_ptr<Wave>& w) {
            bool shouldRemove = w->getPos().first >= WIDTH || w->getPos().first <= -5;
            if (shouldRemove) removeObserver(w.get());
            return shouldRemove;
        }), smallWaves.end());

    bigWaves.erase(std::remove_if(bigWaves.begin(), bigWaves.end(),
        [this](const std::unique_ptr<Wave>& w) {
            bool shouldRemove = w->getPos().first >= WIDTH;
            if (shouldRemove) removeObserver(w.get());
            return shouldRemove;
        }), bigWaves.end());
}