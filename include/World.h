 #pragma once
 #include <vector>
 #include "Car.h"

class World {
public:
    int width = 20;
    int height = 10;
    std::vector<std::vector<char>> map;

    World();
    void initMap();
    void printMap(const std::vector<Car>& cars);
};