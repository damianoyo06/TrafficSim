#include "World.h"
#include "Car.h"
#include <iostream>

World::World() {
    initMap();
}

void World::initMap() {
    map = std::vector<std::vector<char>>(height, 
        std::vector<char>(width, 'E'));

        for(int x = 1; x <width-1; x++){
            map[5][x] = '-';
        }

        for(int x=5; x<16; x++){
            map[2][x] = '-';
            map[7][x] = '-';
        }

      for(int y  = 2; y<7; y++){
            map[y][5] = '|';
            map[y][15] = '|';
        }


        for(int y = 1; y < height-1; y++){
            map[y][10] = '|';
        }

        map[5][10] = '+';
        map[2][10] = '+';
        map[7][10] = '+';
        map[5][5] = '+';
        map[5][15] = '+';
        map[2][5] = '+';
        map[2][15] = '+';
        map[7][5] = '+';
        map[7][15] = '+';

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