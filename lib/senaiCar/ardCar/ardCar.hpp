#pragma once
#include "../car.hpp"
#include <SoftwareSerial.h>
#include <Servo.h>

extern HBridgeMotor bridge1;
extern HBridgeMotor bridge2;
extern Servo servY;

class ArdCar : public Car{
    public:
    ArdCar();
    void refreshSpeed(const char * const command);
    void controllerForward(const char * const command, SoftwareSerial* response);
    void controllerBackward(const char * const command, SoftwareSerial* response);
    void controllerTurnRight(const char * const command, SoftwareSerial* response);
    void controllerTurnLeft(const char * const command, SoftwareSerial* response);
    void rotationRight(const char * const command, SoftwareSerial* response);
    void rotationLeft(const char * const command, SoftwareSerial* response);
    void controllerStopDirection(const char * const command, SoftwareSerial* response);
    void controllerStop(const char * const command, SoftwareSerial* response);
    void controllerServAxisY(const char * const command, SoftwareSerial* response);
    void controllerServAxisX(const char * const command, SoftwareSerial* response);

    private:
    int speedF = 0;
    int speedL = 0;
    int speedR = 0;
};