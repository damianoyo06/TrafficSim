#include "Car.h"

Car::Car(int startX, int startY) 
: x(startX), y(startY) {}

void Car::update() {
    // For now, just move the car to the right
    x += 1;
}

int Car::getX() const {
    return x;
}

int Car::getY() const {
    return y;
}