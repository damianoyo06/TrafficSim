#include "Car.h"
#include "World.h"
#include <vector>
#include <iostream>
#include <climits>

Car::Car(int startX, int startY)
    : x(startX), y(startY), dx(1), dy(0)
{
}

void Car::update(World& world, const std::vector<Car>& cars)
{
    int nextX = x + dx;
    int nextY = y + dy;

    // Prevent out-of-bounds crash
    if (nextX < 0 || nextX >= world.width ||
        nextY < 0 || nextY >= world.height)
    {
        return;
    }

    Position nextPos{nextX, nextY};

    // Traffic light check
    if (world.trafficLights.count(nextPos))
    {
        if (world.trafficLights.at(nextPos).getState() == LightState::Red)
        {
            return;
        }
    }

    std::string nextTile = world.map[nextY][nextX];

    int prevX = x;
    int prevY = y;

    for(const auto& car:cars){
        if(car.getX() == nextX && car.getY() == nextY){
            return; //collision with another car
        }
    }

    // Move only on road
    if (nextTile == "🟩" || nextTile == "🚦")
    {
        x = nextX;
        y = nextY;

        int bestDx = dx;
        int bestDy = dy;
        int bestDistance = INT_MAX;

        const int directions[4][2] =
        {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };

        for (auto& dir : directions)
        {
            int nx = x + dir[0];
            int ny = y + dir[1];

            // Bounds check
            if (nx < 0 || nx >= world.width ||
                ny < 0 || ny >= world.height)
            {
                continue;
            }

            std::string tile = world.map[ny][nx];

            if (tile == "🟩" || tile == "🚦")
            {
                // Don't instantly reverse
                if (nx == prevX && ny == prevY)
                    continue;

                int distance =
                    (nx - world.targetX)*(nx - world.targetX) +
                    (ny - world.targetY)*(ny - world.targetY);

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

    // Reached target -> respawn one shared target
    if (x == world.targetX && y == world.targetY)
    {
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