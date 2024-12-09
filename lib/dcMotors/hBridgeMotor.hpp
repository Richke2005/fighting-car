#pragma once
#include <Arduino.h>

struct pinMotors{
	uint8_t direction1;
  uint8_t direction2;
  uint8_t PWM = 0;
  void accelerationRamp(uint8_t direction, uint8_t velocity);
};


class HBridgeMotor{
  pinMotors motorA;
  pinMotors motorB;
  
  public:
  /**
   * @class HBridgeMotor
   * @brief A class to control an H-Bridge motor driver.
   * 
   * This class provides methods to control two motors (motorA and motorB) using an H-Bridge motor driver.
   */

  /**
   * @brief Default constructor for HBridgeMotor.
   */
  HBridgeMotor();

  /**
   * @brief Constructor for HBridgeMotor with specified pins for two motors.
   * 
   * @param pin1A Pin number for motor A input 1.
   * @param pin2A Pin number for motor A input 2.
   * @param pin1B Pin number for motor B input 1.
   * @param pin2B Pin number for motor B input 2.
   */
  HBridgeMotor(byte pin1A, byte pin2A, byte pin1B, byte pin2B);

  /**
   * @brief Constructor for HBridgeMotor with specified pins for one motor.
   * 
   * @param pin1A Pin number for motor A input 1.
   * @param pin2A Pin number for motor A input 2.
   */
  HBridgeMotor(byte pin1A, byte pin2A);

  /**
   * @brief Initializes the motor pins.
   */
  void initialize();

  /**
   * @brief Sets the state of motor A.
   * 
   * @param isOn Boolean indicating whether the motor is on or off.
   * @param rotationDirection Direction of rotation (0 or 1).
   * @return int Status of the operation.
   */
  int setMotorA(bool isOn, byte rotationDirection);

  /**
   * @brief Sets the velocity and direction of motor A.
   * 
   * @param velocity Speed of the motor (0-255).
   * @param rotationDirection Direction of rotation (0 or 1).
   * @return int Status of the operation.
   */
  int setMotorA(int velocity, byte rotationDirection);

  /**
   * @brief Sets the velocity, direction, and PWM pin of motor A.
   * 
   * @param velocity Speed of the motor (0-255).
   * @param rotationDirection Direction of rotation (0 or 1).
   * @param pinPWM PWM pin for motor A.
   * @return int Status of the operation.
   */
  int setMotorA(int velocity, byte rotationDirection, byte pinPWM);

  /**
   * @brief Sets the state of motor B.
   * 
   * @param isOn Boolean indicating whether the motor is on or off.
   * @param rotationDirection Direction of rotation (0 or 1).
   * @return int Status of the operation.
   */
  int setMotorB(bool isOn, byte rotationDirection);

  /**
   * @brief Sets the velocity and direction of motor B.
   * 
   * @param velocity Speed of the motor (0-255).
   * @param rotationDirection Direction of rotation (0 or 1).
   * @return int Status of the operation.
   */
  int setMotorB(int velocity, byte rotationDirection);

  /**
   * @brief Sets the velocity, direction, and PWM pin of motor B.
   * 
   * @param velocity Speed of the motor (0-255).
   * @param rotationDirection Direction of rotation (0 or 1).
   * @param pinPWM PWM pin for motor B.
   * @return int Status of the operation.
   */
  int setMotorB(int velocity, byte rotationDirection, byte pinPWM);

  /**
   * @brief Continuously sets the state of motor A.
   * 
   * @param isOn Boolean indicating whether the motor is on or off.
   * @param rotationDirection Direction of rotation (0 or 1).
   * @return int Status of the operation.
   */
  int continuousSetMotorA(uint8_t isOn, byte rotationDirection);

  /**
   * @brief Continuously sets the state of motor B.
   * 
   * @param isOn Boolean indicating whether the motor is on or off.
   * @param rotationDirection Direction of rotation (0 or 1).
   * @return int Status of the operation.
   */
  int continuousSetMotorB(uint8_t isOn, byte rotationDirection);
};