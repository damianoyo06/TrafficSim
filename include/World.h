 #pragma once
 #include <vector>
 #include "Car.h"

class World {
public:
    int width = 20;
    int height = 15;
    std::vector<std::vector<std::string>> map;

    std::pair<int, int> getCenter() const;

    World();
    void initMap();
    void printMap(const std::vector<Car>& cars);
};