#pragma once
#include <unordered_set>
#include "observer.h"

class Subject {
public:
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notifyObservers();
private:
    std::unordered_set<Observer*> observers;
};