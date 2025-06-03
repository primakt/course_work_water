#include "river.h"
#include "small_wave_factory.h"
#include "big_wave_factory.h"
#include "console_utils.h"
#include <algorithm>
#include <cstdlib>

River::River() : smallWaveFactory(new SmallWaveFactory()),
                 bigWaveFactory(new BigWaveFactory()) {
    for (int y = 6; y < 12; ++y) {
        for (int i = 0; i < 3; ++i) {
            auto wave = smallWaveFactory->createWave(rand() % 80, y);
            addObserver(wave.get());
            smallWaves.push_back(std::move(wave));
        }
    }
}

void River::draw() {
    setColor(BLUE);
    for (int y = 6; y < 12; ++y) {
        gotoxy(0, y);
        std::cout << std::string(80, '~');
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
        auto wave = smallWaveFactory->createWave(-1, 6 + rand() % 6);
        addObserver(wave.get());
        smallWaves.push_back(std::move(wave));
    }
    
    if (rand() % 200 == 0) {
        auto wave = bigWaveFactory->createWave(-5, 6 + rand() % 6);
        addObserver(wave.get());
        bigWaves.push_back(std::move(wave));
    }
    
    notifyObservers();

    smallWaves.erase(std::remove_if(smallWaves.begin(), smallWaves.end(),
        [this](const std::unique_ptr<Wave>& w) {
            bool shouldRemove = w->getPos().first >= 80;
            if (shouldRemove) removeObserver(w.get());
            return shouldRemove;
        }), smallWaves.end());

    bigWaves.erase(std::remove_if(bigWaves.begin(), bigWaves.end(),
        [this](const std::unique_ptr<Wave>& w) {
            bool shouldRemove = w->getPos().first >= 80;
            if (shouldRemove) removeObserver(w.get());
            return shouldRemove;
        }), bigWaves.end());
}