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
    // atualizar bridges decidir se externas ou internas
    HBridgeMotor bridge1;
    HBridgeMotor bridge2;

    public:
    Car();


    void setBridges(byte, byte, byte, byte);
    void getBattery();
    int getVelocity();
    void foward();
    void backward();
    void foward(int);
    void backward(int);
    void turnRight();
    void turnLeft();
};