 #pragma once
 #include <vector>
 #include "Car.h"
 #include "TrafficLight.h"
 #include "Direction.h"
 #include <map>

struct Position{
    int x, y;

    bool operator<(const Position& other) const {
        return std::tie(x, y) < std::tie(other.x, other.y);
    }   
};

enum TileType{
    Road,
    Junction
};

class World {
public:
    static constexpr int width = 20;
    static constexpr int height = 20;

    // Direction roadDirection[height][width];
    // std::vector<std::vector<Direction>> roadDirection;
    std::vector<std::vector<std::vector<Direction>>> allowedMoves;
    std::vector<std::vector<std::string>> map;
    std::map<Position, TrafficLight> trafficLights;
    int targetX = width/2, targetY = height/2;

    void respawnTarget();

    std::pair<int, int> getCenter() const;
    

    World();
    void initMap();
    void printMap(const std::vector<Car>& cars);
};