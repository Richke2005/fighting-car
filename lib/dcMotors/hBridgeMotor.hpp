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
    /**
    * @brief Constructs an HBridgeMotor object with four input pins for controlling two separate motors.
    *
    * @param[in] pin1A The first pin for controlling the direction of the first motor.
    * @param[in] pin2A The second pin for controlling the direction of the first motor.
    * @param[in] pin1B The first pin for controlling the direction of the second motor.
    * @param[in] pin2B The second pin for controlling the direction of the second motor.
    */
    HBridgeMotor(byte pin1A, byte pin2A, byte pin1B, byte pin2B);

    /**
    * @brief Constructs an HBridgeMotor object with two input pins for controlling the direction of a single motor.
    *
    * This constructor initializes an HBridgeMotor object with two input pins for controlling the direction of a single motor.
    * The two input pins are used to control the direction of the motor by setting the state of the pins high or low.
    *
    * @param[in] pin1A The first pin for controlling the direction of the motor.
    * @param[in] pin2A The second pin for controlling the direction of the motor.
    */
    HBridgeMotor(byte pin1A, byte pin2A);
  
    /**
    * @brief Initializes the HBridgeMotor object by setting the input pins as output pins.
    *
    * This function initializes the HBridgeMotor object by setting the input pins for controlling the direction of the motors as output pins.
    * This is a necessary step before the motors can be controlled.
    *
    * @param None
    * @return None
    */
    void initialize();

    /**
    * @brief Sets the state of the first motor.
    *
    * This function sets the state of the first motor based on the input parameters. The first parameter, 'isOn', determines whether the motor should be turned on or off. If 'isOn' is true, the motor will be turned on; if it is false, the motor will be turned off. The second parameter, 'rotationDirection', determines the direction of the motor's rotation. It can take the values 1 or 2, corresponding to the first and second direction pins of the motor, respectively.
    *
    * @param[in] isOn A boolean value indicating whether the motor should be turned on (true) or off (false).
    * @param[in] rotationDirection An integer value representing the direction of the motor's rotation. It can take the values 1 or 2, corresponding to the first and second direction pins of the motor, respectively.
    */
    void setMotorA(bool isOn, byte rotationDirection);

    // @param[in] velocity velocity passado em porcentagem representa a velocidade do motor.
    void setMotorA(float velocity, byte rotationDirection);

    /**
    * @brief Sets the state of the second motor.
    *
    * This function sets the state of the second motor based on the input parameters. The first parameter, 'isOn', determines whether the motor should be turned on or off. If 'isOn' is true, the motor will be turned on; if it is false, the motor will be turned off. The second parameter, 'rotationDirection', determines the direction of the motor's rotation. It can take the values 1 or 2, corresponding to the first and second direction pins of the motor, respectively.
    *
    * @param[in] isOn A boolean value indicating whether the motor should be turned on (true) or off (false).
    * @param[in] rotationDirection An integer value representing the direction of the motor's rotation. It can take the values 1 or 2, corresponding to the first and second direction pins of the motor, respectively.
    */
    void setMotorB(bool isOn, byte rotationDirection);

    // @param[in] velocity passado em porcentagem representa a velocidade do motor.
    void setMotorB(float velocity, byte rotationDirection);

    void continuousSetMotorA(uint8_t isOn, byte rotationDirection);
    void continuousSetMotorA(char command);

    void continuousSetMotorB(uint8_t isOn, byte rotationDirection);
    void continuousSetMotorB(char command);
};