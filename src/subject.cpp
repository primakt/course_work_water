#include "subject.h"

void Subject::addObserver(Observer* observer) {
    observers.insert(observer);
}

void Subject::removeObserver(Observer* observer) {
    observers.erase(observer);
}

void Subject::notifyObservers() {
    auto observersCopy = observers; // Защита от concurrent modification
    for (auto observer : observersCopy) {
        if (observers.find(observer) != observers.end()) {
            observer->update();
        }
    }
}