#include "renderer.h"
#include <chrono>
#include <thread>

void Renderer::run() {
    while (true) {
        river.update();
        river.draw();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}