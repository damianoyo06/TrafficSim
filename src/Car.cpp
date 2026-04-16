 #include "Car.h"
 #include "World.h"
#include <iostream>

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

    if(nextTile == '+') {
          std::swap(dx, dy); //turn right
        //randomly decide to turn at the intersection
        if(rand() % 2 == 0) {
          
            dx = -dx; //turn right
        } else {
          //  std::swap(dx, dy);
         //   dx = -dx; //turn left
            dy = -dy; //turn left
        }
       
    }
    
    
    
}

int Car::getX() const {
    return x;
}

int Car::getY() const {
    return y;
}