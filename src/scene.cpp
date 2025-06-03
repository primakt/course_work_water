#include "scene.h"

void Scene::draw() {
    for (auto& obj : objects) {
        obj->draw();
    }
}

void Scene::update() {
    notifyObservers();
}