#pragma once

enum class LightState {
    Red,
    Green
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