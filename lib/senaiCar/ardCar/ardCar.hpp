#pragma once
#include "../car.hpp"
#include <SoftwareSerial.h>
#include <Servo.h>

extern HBridgeMotor bridge1;
extern HBridgeMotor bridge2;

class ArdCar : public Car{
    public:
    ArdCar();
    void controllerForward(char* command, SoftwareSerial* response);
    void controllerBackward(char* command, SoftwareSerial* response);
    void controllerTurnRight(char* command, SoftwareSerial* response);
    void controllerTurnLeft(char* command, SoftwareSerial* response);
    void controllerStopDirection(char* command, SoftwareSerial* response);
    void controllerStop(char* command, SoftwareSerial* response);
    void controllerServAxisY(char* command, SoftwareSerial* response);
    void controllerServAxisX(char* command, SoftwareSerial* response);
};