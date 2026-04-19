#include "World.h"
#include "Car.h"
#include <iostream>

World::World() {
    initMap();
}

void World::initMap() {
    map = std::vector<std::vector<char>>(height, 
        std::vector<char>(width, 'E'));

        int midX = width/2;
        int midY = height/2;

        int left = width/5;
        int right = width/5*4;

        int top = height/4;
        int bottom = 3*height/4;

        for(int x = 1; x <width-1; x++){
            map[midY][x] = '-';
        }

        for(int x=width/5; x<width/5*4; x++){
            map[top][x] = '-';
            map[bottom][x] = '-';
        }

      for(int y  = height/4; y<3*height/4; y++){
            map[y][left] = '|';
            map[y][right] = '|';
        }


        for(int y = 1; y < height-1; y++){
            map[y][midX] = '|';
        }

        map[midY][midX] = '+';
        map[top][midX] = '+';
        map[bottom][midX] = '+';
        map[top][left] = '+';
        map[top][right] = '+';
        map[bottom][left] = '+';
        map[bottom][right] = '+';
        map[midY][left] = '+';
        map[midY][right] = '+';

       

}

 std::pair<int, int> World::getCenter() const {
            return {width/2, height/2};
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