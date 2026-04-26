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

        int midX = width/2;
        int midY = height/2;

        int left = width/5;
        int right = width/5*4;

        int top = height/4;
        int bottom = 3*height/4;

        for(int x = left; x <right; x++){
            map[midY][x] = "🟩";
        }

        for(int x=width/5; x<width/5*4; x++){
            map[top][x] = "🟩";
            map[bottom][x] = "🟩";
        }

      for(int y  = height/4; y<3*height/4; y++){
            map[y][left] = "🟩";
            map[y][right] = "🟩";
        }


        for(int y = top; y < bottom; y++){
            map[y][midX] = "🟩";
        }

     //   map[midY][midX] = "🟩";
        map[midY][midX] = "🚦";
        map[top][midX] = "🟩";
        map[bottom][midX] = "🟩";
        map[top][left] = "🟩";
        map[top][right] = "🟩";
        map[bottom][left] = "🟩";
        map[bottom][right] = "🟩";
        map[midY][left] = "🟩";
        map[midY][right] = "🟩";

        trafficLights[{midX, midY}] = TrafficLight(50); // switches every 5 ticks
       

}

 std::pair<int, int> World::getCenter() const {
            return {width/2, height/2};
        }

        
void World::respawnTarget() {
    int newX;
    int newY;

    do {
        newX = rand() % width;
        newY = rand() % height;
    } while (map[newY][newX] == "⬛️");

    targetX = newX;
    targetY = newY;
}
void World::printMap(const std::vector<Car>& cars) {

    auto render = map; //copy the map

    // for(const auto& car : cars) {
    //     render[car.getTargetY()][car.getTargetX()] = "🎯";
    // }

    // render the target
    //render[cars[1].getTargetY()][cars[1].getTargetX()] = "🎯";
    //render[cars[0].getTargetY()][cars[0].getTargetX()] = "🎯";

    render[targetY][targetX] = "🎯";

    //render the cars
    for(const auto& car : cars) {
        render[car.getY()][car.getX()] = "🚗";
    }

    // print the map
    for(int y = 0; y<height; y++){
        for(int x = 0; x<width; x++){
            std::cout << render[y][x];
        }
        std::cout << std::endl;
    }

    for(auto& [pos, light] : trafficLights) {
        light.update(); //update the traffic light state
        std::cout << "Traffic Light at (" << pos.x << ", " << pos.y << "): " 
                  << (light.getState() == LightState::Green ? "🟩" : "🟥") 
                  << std::endl;
    }
}

