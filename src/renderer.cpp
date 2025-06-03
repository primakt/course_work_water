#include "renderer.h"
#include "sky.h"
#include "sun.h"
#include "forest.h"
#include "river.h"
#include <memory>

void Renderer::run() {
    scene.add(std::unique_ptr<Drawable>(new Sky()));
    scene.add(std::unique_ptr<Drawable>(new Sun()));
    scene.add(std::unique_ptr<Drawable>(new Forest()));
    scene.add(std::unique_ptr<Drawable>(new River()));
    
    while (true) {
        scene.update();
        scene.draw();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}