 #pragma once
 #include <vector>
 #include "Car.h"
 #include "TrafficLight.h"
 #include <map>

struct Position{
    int x, y;

    bool operator<(const Position& other) const {
        return std::tie(x, y) < std::tie(other.x, other.y);
    }   
};

class World {
public:
    int width = 20;
    int height = 15;
    std::vector<std::vector<std::string>> map;
    std::map<Position, TrafficLight> trafficLights;
    int targetX = width/2, targetY = height/2;

    void respawnTarget();

    std::pair<int, int> getCenter() const;

    World();
    void initMap();
    void printMap(const std::vector<Car>& cars);
};