 #pragma once
 #include <vector>
 #include "Direction.h"

class World;
class Car {
public:
    Car(int StartX, int StartY);
    void update(World& world, const std::vector<Car>& cars);
    Direction dir;

    int getX() const;
    int getY() const;

private:
    int x, y;

    int targetX, targetY;
};