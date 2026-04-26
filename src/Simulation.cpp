#include "Simulation.h"
#include "World.h"
#include <iostream>
#include <thread>
#include <chrono>

void Simulation::run()
{

    // create cars before loop
    auto [x, y] = world.getCenter();
    cars.emplace_back(x, y);
    cars.emplace_back(5, 7);

   
    while (true)
    {
        // Update cars
        for (auto &car : cars)
        {
            car.update(world, cars);
        }
        // Render
        world.printMap(cars);


        std::this_thread::sleep_for(std::chrono::milliseconds(300));

    }
};