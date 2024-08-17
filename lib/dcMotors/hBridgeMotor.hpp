#pragma once
#include <Arduino.h>

struct pinMotors{
	byte direction1;
  byte direction2;
};

class HBridgeMotor{
	  pinMotors motorA;
  	pinMotors motorB;

    public:
    HBridgeMotor();
    HBridgeMotor(byte pin1A, byte pin2A, byte pin1B, byte pin2B);
    HBridgeMotor(byte pin1A, byte pin2A);
    void initialize();
    void setMotorA(bool isOn, byte rotationDirection);
    void setMotorB(bool isOn, byte rotationDirection);
};