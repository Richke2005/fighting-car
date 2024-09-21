#pragma once
#include <Arduino.h>
#include "../dcMotors/hBridgeMotor.hpp"

class Car {
    protected: 
    float battery;
    float velocity;
    bool connectionStatus;
    float objectRadar;

    public:
    Car();


    void setBridges(HBridgeMotor*, HBridgeMotor*);
    void getBattery();
    int getVelocity();
    void foward();
    void backward();
    void foward(int);
    void backward(int);
    void turnRight();
    void turnLeft();
};