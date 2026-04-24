#include "World.h"
#include "Car.h"
#include "TrafficLight.h"
#include <iostream>

World::World() {
    initMap();
}

void World::initMap() {
    map = std::vector<std::vector<std::string>>(height, 
        std::vector<std::string>(width, "⬛️"));

        //BLUE = NORTH
        //GREEN = SOUTH
        //RED = WEST
        //YELLOW = EAST
        
        // 🟦 northbound
        // 🟩 southbound
        // 🟥 westbound
        // 🟨 eastbound

        //MOVEMENT ON THE LEFT HAND SIDE OF THE ROAD

        int midX = width/2;
        int midY = height/2;

        int left = width/5;
        int right = (width * 4) / 5;;

        int top = height/4;
        int bottom = (height * 3) / 4;

        // NORTH (blue)
for(int y = 1; y < height-1; y++)
{
    map[y][midX-1] = "🟦";
}

for(int y = top; y < bottom; y++)
{
    map[y][left-1]  = "🟦";
    map[y][right-1] = "🟦";
}


// SOUTH (green)
for(int y = 1; y < height-1; y++)
{
    map[y][midX] = "🟩";
}

for(int y = top; y < bottom; y++)
{
    map[y][left]  = "🟩";
    map[y][right] = "🟩";
}


// WEST (red) upper lane
for(int x = 1; x < width-1; x++)
{
    map[midY-1][x] = "🟥";
}

for(int x = left; x < right; x++)
{
    map[top-1][x]    = "🟥";
    map[bottom-1][x] = "🟥";
}


// EAST (yellow) lower lane
for(int x = 1; x < width-1; x++)
{
    map[midY][x] = "🟨";
}

for(int x = left; x < right; x++)
{
    map[top][x]    = "🟨";
    map[bottom][x] = "🟨";
}

    map[top][midX] = "🚦";
    map[bottom][midX] = "🚦";

    map[top][left] = "🚦";
    map[top][right] = "🚦";

    map[bottom][left] = "🚦";
    map[bottom][right] = "🚦";

    map[midY][left] = "🚦";
    map[midY][right] = "🚦";

    
    trafficLights[{midX, midY}] = TrafficLight(50); // switches every 5 ticks
       

}

 std::pair<int, int> World::getCenter() const {
            return {width/2, height/2};
        }

void World::printMap(const std::vector<Car>& cars) {

    auto render = map; //copy the map

    for(const auto& car : cars) {
        render[car.getTargetY()][car.getTargetX()] = "🎯";
    }

    for(const auto& car : cars) {
        render[car.getY()][car.getX()] = "🚗";
    }

    for(int y = 0; y<height; y++){
        for(int x = 0; x<width; x++){
            std::cout << render[y][x];
        }
        std::cout << std::endl;
    }

    for(auto& [pos, light] : trafficLights) {
        light.update(); //update the traffic light state
        std::cout << "Traffic Light at (" << pos.x << ", " << pos.y << "): " 
                  << (light.getState() == LightState::Green ? "Green" : "Red") 
                  << std::endl;
    }
}

