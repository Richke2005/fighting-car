#include "controller.hpp"

void Controller::controllerForward(char* command, HBridgeMotor* bridge){
    if(*command == 'l'){
    int dirMA = bridge->continuousSetMotorA(HIGH, 1);
    int dirMB = bridge->continuousSetMotorB(HIGH, 1);
        if(dirMA == 0 || dirMB == 0){
            Serial.println("motors are off");

        }
        Serial.println("motor A is on, direction " + (String) dirMA);
        Serial.println("motor B is on, direction " + (String) dirMB);
    }
}

void Controller::controllerBackward(char* command, HBridgeMotor* bridge){
    if(*command == 'r'){
    int dirMA = bridge->continuousSetMotorA(HIGH, 2);
    int dirMB = bridge->continuousSetMotorB(HIGH, 2);
        if(dirMA == 0 || dirMB == 0){
            Serial.println("motors are off");
        }
        Serial.println("motor A is on, direction " + (String) dirMA);
        Serial.println("motor B is on, direction " + (String) dirMB);
    }
}

void Controller::controllerStop(char* command, HBridgeMotor* bridge){
    if(*command == 's'){
        bridge->continuousSetMotorA(LOW, 0);
        bridge->continuousSetMotorB(LOW, 0);
        Serial.println("motors are off");
    }
}