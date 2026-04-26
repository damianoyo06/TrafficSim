 #pragma once
 #include <vector>

class World;
class Car {
public:
    Car(int StartX, int StartY);
    void update(World& world, const std::vector<Car>& cars);

    int getX() const;
    int getY() const;

private:
    int x, y;
    int dx, dy;

    int targetX, targetY;
};