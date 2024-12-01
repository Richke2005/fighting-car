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

int HBridgeMotor::setMotorA(bool isOn, byte rotationDirection){
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
return direction;
}

//TODO: melhorar função para controle do motor
int HBridgeMotor::setMotorB(bool isOn, byte rotationDirection){
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
return direction;
}

int HBridgeMotor::setMotorA(int velocity, byte rotationDirection){
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
    return velocityValue;
}

int HBridgeMotor::setMotorA(int velocity, byte rotationDirection, byte pinPWM){
    byte direction;
    int velocityValue = (velocity * 255) / 100;
    switch (rotationDirection){
    case 1:
        direction = motorA.direction1;
        digitalWrite(direction, HIGH);
        analogWrite(pinPWM, velocityValue);
        break;
    case 2: 
        direction = motorA.direction2;
        digitalWrite(direction, HIGH);
        analogWrite(pinPWM, velocityValue);
        break;
    default:
        direction = 0;
        return 0;
        break;
    }
    digitalWrite(direction, LOW);
   
    delay(135);
    return velocityValue;
}

int HBridgeMotor::setMotorB(int velocity, byte rotationDirection){
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
    return velocityValue;
}

int HBridgeMotor::setMotorB(int velocity, byte rotationDirection, byte pinPWM){
    byte direction;
    int velocityValue = (velocity * 255) / 100;
    switch (rotationDirection){
    case 1:
        direction = motorB.direction1;
        digitalWrite(direction, HIGH);
        analogWrite(pinPWM, velocityValue);
        break;
    case 2: 
        direction = motorB.direction2;
        digitalWrite(direction, HIGH);
        analogWrite(pinPWM, velocityValue);
        break;
    default:
        direction = 0;
        break;
    }
    digitalWrite(direction, LOW);
    delay(135);
    return velocityValue;

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
            break;
        case 2: 
            direction = motorA.direction2;
            contrary = motorA.direction1;
            break;
        default:
            direction = 0;
            contrary = 0;
            break;
        }
        
        analogWrite(contrary, 0);
        analogWrite(direction, isOn);
    }else{
        analogWrite(direction, 0);
        analogWrite(contrary, 0);
    }
    return rotationDirection;
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
            break;
        case 2: 
            direction = motorB.direction2;
            contrary = motorB.direction1;
            break;
        default:
            direction = 0;
            contrary = 0;
            break;
        }
        
        analogWrite(contrary, 0);
        analogWrite(direction, isOn);
    }else{
        analogWrite(direction, 0);
        analogWrite(contrary, 0);
    }
    return rotationDirection;
}

void pinMotors::accelerationRamp(uint8_t direction, uint8_t velocity) {
    static unsigned long lastUpdate = 0; // Tempo da última atualização
    // Determina a direção da rampa
    if (velocity == 0) {
        this->PWM = 0;
        analogWrite(direction, this->PWM);
    } else if (this->PWM == 0) {
        this->PWM = 128; // Inicia a rampa de aceleração
    }

    // Verifica se passou o intervalo de tempo (5ms)
    if (millis() - lastUpdate >= 5 && this->PWM != 0) {
        lastUpdate = millis(); // Atualiza o tempo da última execução
        // Atualiza o valor de PWM gradualmente até o valor desejado
        this->PWM = constrain(this->PWM + 1, 0, velocity);
        analogWrite(direction, this->PWM);
        Serial.println(this->PWM);
    }
}
