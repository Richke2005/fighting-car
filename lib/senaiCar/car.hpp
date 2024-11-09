#pragma once
#include <SoftwareSerial.h>
#include "../dcMotors/hBridgeMotor.hpp"
#include "../../include/config.hpp"

struct batteryLeds{
    uint8_t greenLed;
    uint8_t yellowLed;
    uint8_t redLed;
};

class Car {
    protected: 
    uint8_t pinBattery;
    float battery;
    float velocity;
    bool connectionStatus;
    float objectRadar;
    batteryLeds leds;
    
    public:
    Car();
    Car(uint8_t pin);
    void attachBattery(uint8_t pinBattery);
    void attachLeds(uint8_t redLed, uint8_t yellowLed, uint8_t greenLed);
    void controlBatteryLeds();
    float getBattery();
    float getBatteryToPercent();
    int getVelocity();
};