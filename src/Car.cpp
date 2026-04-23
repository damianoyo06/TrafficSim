#include "Car.h"
#include "World.h"
#include <iostream>

// Set initial direction to right and target to center of the map
Car::Car(int startX, int startY)
    : x(startX), y(startY), dx(1), dy(0)
{

    targetX = World().width / 2;
    ;
    targetY = World().height / 2;
}

// Simple logic: try to move in the current direction, if hitting a wall turn back, if on an intersection choose the direction that gets closer to the target
void Car::update(const World &world)
{

   
    int nextX = x + dx;
    int nextY = y + dy;

    Position nextPos{nextX, nextY};

    if (world.trafficLights.count(nextPos))
    {
        if (world.trafficLights.at(nextPos).getState() == LightState::Red)
        {
            return; // STOP at red light
        }
    }

    std::string nextTile = world.map[nextY][nextX];

     // Check for traffic light at the next position
    int prevX = x;
    int prevY = y;


    // //only move if the next tile is a road
    if (nextTile == "🟩" || nextTile == "🚦")
    {
        x = nextX;
        y = nextY;

        int bestDx = 0, bestDy = 0;
        int bestDistance = INT_MAX;

        // possible directions to turn: right, left, up, down
        const int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (auto &dir : directions)
        {
            int nx = x + dir[0];
            int ny = y + dir[1];

            std::string tile = world.map[ny][nx];

            if (tile == "🟩" || tile == "🚦")
            {

                if (nx == prevX && ny == prevY)
                    continue; // don't go back

                int distance = (nx - targetX) * (nx - targetX) + (ny - targetY) * (ny - targetY);
                if (distance < bestDistance)
                {
                    bestDistance = distance;
                    bestDx = dir[0];
                    bestDy = dir[1];
                }
            }
        }
        dx = bestDx;
        dy = bestDy;
    }

    if (targetX == x && targetY == y)
    {
        int newX;
        int newY;

        do
        {
            newX = rand() % world.width;
            newY = rand() % world.height;
        } while (world.map[newY][newX] == "⬛️");

        targetX = newX;
        targetY = newY;

        std::cout << "target: " << targetX << ", " << targetY << std::endl;
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

int Car::getTargetX() const
{
    return targetX;
}

int Car::getTargetY() const
{
    return targetY;
}