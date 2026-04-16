#include "World.h"
#include "Car.h"
#include <iostream>

World::World() {
    initMap();
}

void World::initMap() {
    map = std::vector<std::vector<char>>(height, 
        std::vector<char>(width, 'E'));

        for(int x = 0; x <18; x++){
            map[5][x] = '-';
        }

        for(int y = 0; y < 8; y++){
            map[y][10] = '|';
        }

        map[5][10] = '+';

}

void World::printMap(const std::vector<Car>& cars) {

    auto render = map; //copy the map

    for(const auto& car : cars) {
        render[car.getY()][car.getX()] = 'C';
    }

    for(int y = 0; y<height; y++){
        for(int x = 0; x<width; x++){
            std::cout << render[y][x];
        }
        std::cout << std::endl;
    }
}