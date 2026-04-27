#include "Car.h"
#include "World.h"
#include "Direction.h"
#include <vector>
#include <iostream>
#include <climits>

Direction opposite(Direction d) {
    switch(d) {
        case Direction::Right: return Direction::Left;
        case Direction::Left: return Direction::Right;
        case Direction::Up: return Direction::Down;
        case Direction::Down: return Direction::Up;
    }
    return d;
}

Car::Car(int startX, int startY)
    : x(startX), y(startY), dir(Direction::Left)
{
}

void Car::update(World& world, const std::vector<Car>& cars)
{
    
    int nextX = x;
    int nextY = y;

    switch(dir)
    {
        case Direction::Right: nextX++; break;
        case Direction::Left:  nextX--; break;
        case Direction::Down:  nextY++; break;
        case Direction::Up:    nextY--; break;
    }

    Position nextPos{nextX, nextY};

    if(nextX < 0 || nextX >= world.width ||
       nextY < 0 || nextY >= world.height)
        return;

    for(const auto& car : cars)
    {
        if(car.getX()==nextX && car.getY()==nextY)
            return;
    }

     if(world.trafficLights.count(nextPos) &&
               world.trafficLights.at(nextPos).getState() == LightState::Red) {
                return;
            }
    if(world.map[nextY][nextX] == "🟩" ||
       world.map[nextY][nextX] == "🚦")
    {
        if(world.map[nextY][nextX] == "🚦") {
           
            auto options = world.allowedMoves[nextY][nextX];

            std::vector<Direction> filtered;

            for(auto d : options)
            {
                if(d != opposite(dir))
                    filtered.push_back(d);
            }
            if(!filtered.empty())
            {
                dir = filtered[rand() % filtered.size()];
            }
           

            dir = options[rand() % options.size()];
            x = nextX;
            y = nextY;
        } else {
            x = nextX;
            y = nextY;
        }
    }

    if(x == world.targetX && y == world.targetY) {
        world.respawnTarget();
    }
}

int Car::getX() const
{
    return x;
}

int Car::getY() const
{
    return y;
}