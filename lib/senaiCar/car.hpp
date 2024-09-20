#pragma once
#include <Arduino.h>
#include "../dcMotors/hBridgeMotor.hpp"
#include "../include/config.hpp"

class Car {
    protected: 
    float battery;
    float velocity;
    bool connectionStatus;
    float objectRadar;

    public:
    Car();

    void setBridges(HBridgeMotor* motor1);
    void getBattery();
    int getVelocity();
    void foward(HBridgeMotor*, HBridgeMotor*);
    void backward(HBridgeMotor*, HBridgeMotor*);
    void foward(int);
    void backward(int);
    void turnRight();
    void turnLeft();
};