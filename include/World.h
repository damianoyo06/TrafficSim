#pragma once
#include <vector>
#include "Car.h"

class World {
public:
    int width = 10;
    int height = 10;
    std::vector<std::vector<int>> grid;

    World();
    void initGrid();
    void printGrid(const std::vector<Car>& cars);
};