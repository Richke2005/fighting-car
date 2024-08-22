#include <Arduino.h>
#include "hBridgeMotor.hpp"

HBridgeMotor::HBridgeMotor(){
    motorA.direction1 = NULL;
    motorA.direction2 = NULL;
    motorB.direction1 = NULL;
    motorB.direction2 = NULL;
}

/**
 * @brief Constructs an HBridgeMotor object with four input pins for controlling two separate motors.
 *
 * @param[in] pin1A The first pin for controlling the direction of the first motor.
 * @param[in] pin2A The second pin for controlling the direction of the first motor.
 * @param[in] pin1B The first pin for controlling the direction of the second motor.
 * @param[in] pin2B The second pin for controlling the direction of the second motor.
 */
HBridgeMotor::HBridgeMotor(byte pin1A, byte pin2A, byte pin1B, byte pin2B){
    motorA.direction1 = pin1A;
    motorA.direction2 = pin2A;
    motorB.direction1 = pin1B;
    motorB.direction2 = pin2B;
  }

/**
 * @brief Constructs an HBridgeMotor object with two input pins for controlling the direction of a single motor.
 *
 * This constructor initializes an HBridgeMotor object with two input pins for controlling the direction of a single motor.
 * The two input pins are used to control the direction of the motor by setting the state of the pins high or low.
 *
 * @param[in] pin1A The first pin for controlling the direction of the motor.
 * @param[in] pin2A The second pin for controlling the direction of the motor.
 */
HBridgeMotor::HBridgeMotor(byte pin1A, byte pin2A){
    motorA.direction1 = pin1A;
    motorA.direction2 = pin2A;
}

/**
 * @brief Initializes the HBridgeMotor object by setting the input pins as output pins.
 *
 * This function initializes the HBridgeMotor object by setting the input pins for controlling the direction of the motors as output pins.
 * This is a necessary step before the motors can be controlled.
 *
 * @param None
 * @return None
 */
void HBridgeMotor::initialize(){
    pinMode(motorA.direction1, OUTPUT);
    pinMode(motorA.direction2, OUTPUT);
    pinMode(motorB.direction1, OUTPUT);
    pinMode(motorB.direction2, OUTPUT);
}

/**
 * @brief Sets the state of the first motor.
 *
 * This function sets the state of the first motor based on the input parameters. The first parameter, 'isOn', determines whether the motor should be turned on or off. If 'isOn' is true, the motor will be turned on; if it is false, the motor will be turned off. The second parameter, 'rotationDirection', determines the direction of the motor's rotation. It can take the values 1 or 2, corresponding to the first and second direction pins of the motor, respectively.
 *
 * @param[in] isOn A boolean value indicating whether the motor should be turned on (true) or off (false).
 * @param[in] rotationDirection An integer value representing the direction of the motor's rotation. It can take the values 1 or 2, corresponding to the first and second direction pins of the motor, respectively.
 */
void HBridgeMotor::setMotorA(bool isOn, byte rotationDirection){
    byte direction;
    if(rotationDirection == 1)
        direction = motorA.direction1;
    else 
        direction = motorA.direction2;
    if(isOn){
        digitalWrite(direction, HIGH);
        Serial.println("pin: " + (String) direction + "ligado");
    }
digitalWrite(direction, LOW);
}

/**
 * @brief Sets the state of the second motor.
 *
 * This function sets the state of the second motor based on the input parameters. The first parameter, 'isOn', determines whether the motor should be turned on or off. If 'isOn' is true, the motor will be turned on; if it is false, the motor will be turned off. The second parameter, 'rotationDirection', determines the direction of the motor's rotation. It can take the values 1 or 2, corresponding to the first and second direction pins of the motor, respectively.
 *
 * @param[in] isOn A boolean value indicating whether the motor should be turned on (true) or off (false).
 * @param[in] rotationDirection An integer value representing the direction of the motor's rotation. It can take the values 1 or 2, corresponding to the first and second direction pins of the motor, respectively.
 */

//TODO: melhorar função para controle do motor
void HBridgeMotor::setMotorB(bool isOn, byte rotationDirection){
    byte direction;
    switch (rotationDirection)
    {
    case 1:
        direction = motorB.direction1;
        break;
    
    case 2: 
        direction = motorB.direction2;
        break;
    default:
        direction = NULL;
        break;
    }
    if(isOn){
        digitalWrite(direction, HIGH);
    }
digitalWrite(direction, LOW);
}

// @param[in] velocity passado em porcentagem representa a velocidade do motor.
void HBridgeMotor::setMotorA(float velocity, byte rotationDirection){
    byte direction;
    //TODO: implementar função para controle de velocidade
    int velocityValue = (velocity * 255) / 100;
    switch (rotationDirection)
    {
    case 1:
        direction = motorA.direction1;
        break;
    case 2: 
        direction = motorA.direction2;
        break;
    default:
        direction = NULL;
        break;
    }
    analogWrite(velocityValue, direction);
}

void HBridgeMotor::setMotorB(float velocity, byte rotationDirection){
    byte direction;
    int velocityValue = (velocity * 255) / 100;
    switch (rotationDirection)
    {
    case 1:
        direction = motorA.direction1;
        break;
    case 2: 
        direction = motorA.direction2;
        break;
    default:
        direction = NULL;
        break;
    }
    analogWrite(velocityValue, direction);
}