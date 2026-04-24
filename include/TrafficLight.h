#pragma once

enum class LightState {
    Green,
    Red
};

class TrafficLight {
private:
    LightState state;
    int timer;
    int switchDuration;

public:
    TrafficLight();
    TrafficLight(int interval);

    void update();
    LightState getState() const;
};