#pragma once
#include "World.h"
#include "Car.h"
#include <vector>

class Simulation {
    public:
    void run();

    private:
        World world;
        std::vector<Car> cars;
};