 #pragma once
 #include <vector>
 #include "Car.h"

class World {
public:
    int width = 20;
    int height = 20;
    std::vector<std::vector<char>> map;
    std::pair<int, int> getCenter() const;

    World();
    void initMap();
    void printMap(const std::vector<Car>& cars);
};