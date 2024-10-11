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
    if(isOn){
        switch (rotationDirection)
        {
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
        digitalWrite(direction, HIGH);
        delay(135);
    }
digitalWrite(direction, LOW);
}

//TODO: melhorar função para controle do motor
void HBridgeMotor::setMotorB(bool isOn, byte rotationDirection){
    byte direction;
    if(isOn){
        switch (rotationDirection)
        {
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

int HBridgeMotor::setMotorA(float velocity, byte rotationDirection, byte pinPWM){
    byte direction;
    int velocityValue = (velocity * 255) / 100;
    switch (rotationDirection){
    case 1:
        direction = motorA.direction1;
        digitalWrite(direction, HIGH);
        analogWrite(pinPWM, velocityValue);
        return velocityValue;
        break;
    case 2: 
        direction = motorA.direction2;
        digitalWrite(direction, HIGH);
        analogWrite(pinPWM, velocityValue);
        return velocityValue;
        break;
    default:
        direction = 0;
        break;
    }
    digitalWrite(direction, LOW);
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

int HBridgeMotor::setMotorB(float velocity, byte rotationDirection, byte pinPWM){
    byte direction;
    int velocityValue = (velocity * 255) / 100;
    switch (rotationDirection){
    case 1:
        direction = motorB.direction1;
        digitalWrite(direction, HIGH);
        analogWrite(pinPWM, velocityValue);
        return velocityValue;
        break;
    case 2: 
        direction = motorB.direction2;
        digitalWrite(direction, HIGH);
        analogWrite(pinPWM, velocityValue);
        return velocityValue;
        break;
    default:
        direction = 0;
        break;
    }
    digitalWrite(direction, LOW);
    delay(135);
}



int HBridgeMotor::continuousSetMotorA(uint8_t isOn, byte rotationDirection){
    byte direction = motorA.direction1;
    byte contrary = motorA.direction2;
    if(isOn){
        switch (rotationDirection)
        {
        case 1:
            direction = motorA.direction1;
            contrary = motorA.direction2;
            digitalWrite(direction, isOn);
            digitalWrite(contrary, !isOn);
            return 1;
            break;
    
        case 2: 
            direction = motorA.direction2;
            contrary = motorA.direction1;
            digitalWrite(direction, isOn);
            digitalWrite(contrary, !isOn);
            return 2;
            break;
        default:
            direction = 0;
            return 0;
            break;
        }
    }else{
        digitalWrite(direction, isOn);
        digitalWrite(contrary, isOn);
        return 0;
    }
}

int HBridgeMotor::continuousSetMotorB(uint8_t isOn, byte rotationDirection){
    byte direction = motorB.direction1;
    byte contrary = motorB.direction2;
    if(isOn){
        switch (rotationDirection)
        {
        case 1:
            direction = motorB.direction1;
            contrary = motorB.direction2;
            digitalWrite(direction, isOn);
            digitalWrite(contrary, !isOn);
            return 1;
            break;
    
        case 2: 
            direction = motorB.direction2;
            contrary = motorB.direction1;
            digitalWrite(direction, isOn);
            digitalWrite(contrary, !isOn);
            return 2;
            break;
        default:
            direction = 0;
            break;
        }
    }else{
        digitalWrite(direction, isOn);
        digitalWrite(contrary, isOn);
        return isOn;
    }
}