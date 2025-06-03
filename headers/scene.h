#pragma once
#include "drawable.h"
#include "subject.h"
#include <memory>
#include <vector>

class Scene : public Drawable, public Subject {
public:
    template<typename T>
    void add(std::unique_ptr<T> obj) {
        addObserver(obj.get());
        objects.push_back(std::move(obj));
    }
    
    void draw() override;
    void update() override;
    
private:
    std::vector<std::unique_ptr<Drawable>> objects;
};