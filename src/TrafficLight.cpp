#include "TrafficLight.h"

TrafficLight::TrafficLight():
    state(LightState::Green), timer(0), switchDuration(0) {}

TrafficLight::TrafficLight(int interval):
    state(LightState::Green), timer(0), switchDuration(interval) {}

void TrafficLight::update() {
    timer++;

    if(timer > switchDuration){
        timer = 0;
        state = (state == LightState::Green) ? LightState::Red : LightState::Green;
    }
}

LightState TrafficLight::getState() const{
    return state;
}