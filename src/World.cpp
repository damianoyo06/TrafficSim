#include "World.h"
#include "Car.h"
#include <iostream>

World::World() {
    initGrid();
}

void World::initGrid() {
    grid = std::vector<std::vector<int>>(
        height,
        std::vector<int>(width, 0)
    );
}

void World::printGrid(const std::vector<Car>& cars) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            bool hasCar = false;

            for (const auto& car : cars) {
                if (car.getX() == x && car.getY() == y) {
                    std::cout << "C";
                    hasCar = true;
                    break;
                }
            }

            if (!hasCar) {
                std::cout << ".";
            }
        }
        std::cout << "\n";
    }
}