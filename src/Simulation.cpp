#include "Simulation.h"
#include "World.h"
#include <iostream>
#include <thread>
#include <chrono>

void Simulation::run()
{

    // create cars before loop
    cars.emplace_back(1, 5);

   
    while (true)
    {
        // Update cars
        for (auto &car : cars)
        {
            car.update(world);
        }
        // Render
        world.printMap(cars);


        std::this_thread::sleep_for(std::chrono::milliseconds(300));

    }
};