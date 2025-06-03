#pragma once
#include <unordered_set>
#include "observer.h"

class Subject {
public:
    virtual ~Subject() = default;
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notifyObservers();
protected:
    std::unordered_set<Observer*> observers;
};