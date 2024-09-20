#include <Arduino.h>
#include "hBridgeMotor.hpp"

HBridgeMotor::HBridgeMotor(){
    motorA.direction1 = 0;
    motorA.direction2 = 0;
    motorB.direction1 = 0;
    motorB.direction2 = 0;
}

HBridgeMotor::HBridgeMotor(byte pin1A, byte pin2A, byte pin1B, byte pin2B){
    motorA.direction1 = pin1A;
    motorA.direction2 = pin2A;
    motorB.direction1 = pin1B;
    motorB.direction2 = pin2B;
}

HBridgeMotor::HBridgeMotor(byte pin1A, byte pin2A){
    motorA.direction1 = pin1A;
    motorA.direction2 = pin2A;
}

void HBridgeMotor::initialize(){
    pinMode(motorA.direction1, OUTPUT);
    pinMode(motorA.direction2, OUTPUT);
    pinMode(motorB.direction1, OUTPUT);
    pinMode(motorB.direction2, OUTPUT);
}

void HBridgeMotor::setMotorA(bool isOn, byte rotationDirection){
    byte direction;
    switch (rotationDirection){
    case 1:
        direction = motorA.direction1;
        break;
    
    case 2: 
        direction = motorA.direction2;
        break;
    default:
        direction = 0;
        break;
    }
    if(isOn){
        digitalWrite(direction, HIGH);
        delay(135);
    }
digitalWrite(direction, LOW);
}

//TODO: melhorar função para controle do motor
void HBridgeMotor::setMotorB(bool isOn, byte rotationDirection){
    byte direction;
    switch (rotationDirection){
    case 1:
        direction = motorB.direction1;
        break;
    
    case 2: 
        direction = motorB.direction2;
        break;
    default:
        direction = 0;
        break;
    }
    if(isOn){
        digitalWrite(direction, HIGH);
        delay(135);
    }
digitalWrite(direction, LOW);
}

void HBridgeMotor::setMotorA(float velocity, byte rotationDirection){
    byte direction;
    int velocityValue = (velocity * 255) / 100;
    switch (rotationDirection){
    case 1:
        direction = motorA.direction1;
        break;
    case 2: 
        direction = motorA.direction2;
        break;
    default:
        direction = 0;
        break;
    }
    analogWrite(direction, velocityValue);
    delay(135);
}

void HBridgeMotor::setMotorB(float velocity, byte rotationDirection){
    byte direction;
    int velocityValue = (velocity * 255) / 100;
    switch (rotationDirection){
    case 1:
        direction = motorA.direction1;
        break;
    case 2: 
        direction = motorA.direction2;
        break;
    default:
        direction = 0;
        break;
    }
    analogWrite(direction, velocityValue);
    delay(135);
}

void HBridgeMotor::continuousSetMotorA(bool isOn, byte rotationDirection){
    byte direction, contrary;
    switch (rotationDirection){
    case 1:
        direction = motorA.direction1;
        contrary = motorA.direction2;
        break;
    
    case 2: 
        direction = motorA.direction2;
        contrary = motorA.direction1;
        break;
    default:
        direction = 0;
        break;
    }
    if(isOn){
        digitalWrite(direction, HIGH);
        digitalWrite(contrary, LOW);
        Serial.println("pin " + (String) direction + " HIGH");
        Serial.println("pin " + (String) contrary + " LOW");
    }
}

void HBridgeMotor::continuousSetMotorB(bool isOn, byte rotationDirection){
    byte direction, contrary;
    switch (rotationDirection){
    case 1:
        direction = motorB.direction1;
        contrary = motorB.direction2;
        break;
    
    case 2: 
        direction = motorB.direction2;
        contrary = motorB.direction1;
        break;
    default:
        direction = 0;
        break;
    }
    if(isOn){
        digitalWrite(direction, HIGH);
        digitalWrite(contrary, LOW);
    }
}