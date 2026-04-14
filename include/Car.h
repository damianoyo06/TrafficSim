#pragma once

class Car{
public:
    Car(int StartX, int StartY);
     
    void update();

    int getX() const;
    int getY() const;
private:
    int x;
    int y;
};