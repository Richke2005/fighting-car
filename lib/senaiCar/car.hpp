#pragma once
#include "../dcMotors/hBridgeMotor.hpp"
#include "../../include/config.hpp"

class Car {
    protected: 
    uint8_t pinBattery;
    float battery;
    float velocity;
    bool connectionStatus;
    float objectRadar;
    
    public:
    Car();
    Car(uint8_t pin);
    void attachBattery(uint8_t pinBattery);
    float getBattery();
    int getVelocity();
};