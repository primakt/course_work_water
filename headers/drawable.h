#pragma once
#include "observer.h"

class Drawable : public Observer {
public:
    virtual void draw() = 0;
    virtual ~Drawable() = default;
};