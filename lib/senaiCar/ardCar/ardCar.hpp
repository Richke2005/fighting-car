#pragma once
#include "../car.hpp"
#include <SoftwareSerial.h>
#include <Servo.h>

extern HBridgeMotor bridge1;
extern HBridgeMotor bridge2;

class ArdCar : public Car{
    public:
    ArdCar();
    ArdCar(uint8_t pin);
    static void controllerForward(char* command, SoftwareSerial* response);
    static void controllerBackward(char* command, SoftwareSerial* response);
    static void controllerTurnRight(char* command, SoftwareSerial* response);
    static void controllerTurnLeft(char* command, SoftwareSerial* response);
    static void controllerStopDirection(char* command, SoftwareSerial* response);
    static void controllerStop(char* command, SoftwareSerial* response);
    static void controllerServAxisY(char* command, SoftwareSerial* response);
    static void controllerServAxisX(char* command, SoftwareSerial* response);
};