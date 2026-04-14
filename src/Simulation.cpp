#include "Simulation.h"
#include <iostream>
#include <thread>
#include <chrono>

void Simulation::run() {

    // 1. create cars BEFORE loop
    cars.emplace_back(0, 0);

    while (true) {

        // 2. update cars
        for (auto& car : cars) {
            car.update();
        }

        // 3. render
        world.printGrid(cars);

        // 4. slow down so you can see it
        std::this_thread::sleep_for(std::chrono::milliseconds(300));

        // 5. clear screen (optional but recommended)
        std::cout << "\033[2J\033[H";
    }
}