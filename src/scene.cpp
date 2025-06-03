#include "scene.h"

void Scene::draw() {
    clearScreen();
    for (auto& obj : objects) {
        obj->draw();
    }
}

void Scene::update() {
    notifyObservers();
}