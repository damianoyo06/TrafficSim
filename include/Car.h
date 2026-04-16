 #pragma once

class World;
class Car {
public:
    Car(int StartX, int StartY);
    void update(const World& world);

    int getX() const;
    int getY() const;
private:
    int x, y;
    int dx, dy;
};