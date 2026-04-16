 #include "Car.h"
 #include "World.h"

Car::Car(int startX, int startY) 
: x(startX), y(startY), dx(1), dy(0) {}

void Car::update(const World& world) {
    
    int nextX = x + dx;
    int nextY = y + dy;

    char nextTile = world.map[nextY][nextX];

    //only move if the next tile is a road
    if(nextTile == '-' || nextTile == '|' || nextTile == '+') {
        x = nextX;
        y = nextY;
    } else {
        //turn back when hitting a wall
        dx = -dx;
        dy = -dy;
    } 
    
    
    
}

int Car::getX() const {
    return x;
}

int Car::getY() const {
    return y;
}