#include "subject.h"

void Subject::addObserver(Observer* observer) {
    observers.insert(observer);
}

void Subject::removeObserver(Observer* observer) {
    observers.erase(observer);
}

void Subject::notifyObservers() {
    for (auto observer : observers) {
        observer->update();
    }
}