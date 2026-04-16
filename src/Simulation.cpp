#include "Simulation.h"
#include "World.h"
#include <iostream>
#include <thread>
#include <chrono>

void Simulation::run()
{

    // create cars before loop
    cars.emplace_back(0, 5);

   
    while (true)
    {
        // Update cars
        for (auto &car : cars)
        {
            car.update(world);
        }
        // Render
        world.printMap(cars);

        // Slow down so you can see it
        std::this_thread::sleep_for(std::chrono::milliseconds(300));

    }
};