#pragma once
#include <Arduino.h>
#include <hBridgeMotor.hpp>

class Controller{
    public:
    static void controllerForward(char* command, HBridgeMotor*);
    static void controllerBackward(char* command, HBridgeMotor*);
    static void controllerStop(char* command, HBridgeMotor*);
};