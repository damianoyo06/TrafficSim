#include "World.h"
#include "Car.h"
#include "Direction.h"
#include "TrafficLight.h"
#include <iostream>

World::World()
    : allowedMoves(height, std::vector<std::vector<Direction>>(width, {Direction::Up}))
{
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

        //middle horizontal road
        for(int x = left; x <right; x++){
            map[midY][x] = "🟩";
            allowedMoves[midY][x] = {Direction::Right};
        }

        //top and bottom horizontal roads
        for(int x=width/5; x<width/5*4; x++){
            map[top][x] = "🟩";
            map[bottom][x] = "🟩";
            allowedMoves[top][x] = {Direction::Right};
            allowedMoves[bottom][x] = {Direction::Left};
        }

        //vertical roads on the sides
        for(int y  = height/4; y<3*height/4; y++){
            map[y][left] = "🟩";
            map[y][right] = "🟩";
            allowedMoves[y][left] = {Direction::Up};
            allowedMoves[y][right] = {Direction::Down};
        }

        //vertical road in the middle
        for(int y = top; y < bottom; y++){
            map[y][midX] = "🟩";
            allowedMoves[y][midX] = {Direction::Up};
        }

        //Intersections
        map[midY][midX] = "🚦";
        allowedMoves[midY][midX] = {Direction::Up, Direction:: Right};
        map[top][midX] = "🚦";
        allowedMoves[top][midX] = {Direction::Right};
        map[bottom][midX] = "🚦";
        allowedMoves[bottom][midX] = {Direction::Up, Direction::Left};
        map[top][left] = "🚦";
        allowedMoves[top][left] = {Direction::Right};
        map[top][right] = "🚦";
        allowedMoves[top][right] = {Direction::Down};
        map[bottom][left] = "🚦";
        allowedMoves[bottom][left] = {Direction::Up};
        map[bottom][right] = "🚦";
        allowedMoves[bottom][right] = {Direction::Left};
        map[midY][left] = "🚦";
        allowedMoves[midY][left] = {Direction::Up, Direction::Right};
        map[midY][right] = "🚦";
        allowedMoves[midY][right] = {Direction::Down};

        trafficLights[{midX, midY}] = TrafficLight(50); // switches every 5 ticks
       
        // Set allowed moves for junction
       // allowedMoves[midY][midX] = {Direction::Up, Direction::Down, Direction::Left, Direction::Right};

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

