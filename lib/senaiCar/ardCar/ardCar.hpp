#pragma once
#include "../car.hpp"
#include <SoftwareSerial.h>
#include <SoftwareServo.h>
/**
 * @file ardCar.hpp
 * @brief Header file for the ArdCar class, which extends the Car class and provides methods for controlling a car using H-Bridge motors and servos.
 */

extern HBridgeMotor bridge1;
extern HBridgeMotor bridge2;
extern SoftwareServo servY;


class ArdCar : public Car{
    uint8_t speedF = 0;
    uint8_t speedL = 0;
    uint8_t speedR = 0;
    unsigned long lastUpdate = 0;
    /**
    * @class ArdCar
    * @brief A class to control a car with H-Bridge motors and servos.
    */
    public:

    ArdCar();
    /**
    * @brief Constructor for the ArdCar class.
    */
    void controllerForward(char command);
     
 /**
    * @brief Controls the car to move forward based on the given command.
    * @param command A character representing the command.
    * @param response A pointer to a SoftwareSerial object for sending responses.
    */
    void controllerBackward(char command);
     /**
    * @brief Controls the car to move backward based on the given command.
    * @param command A character representing the command.
    * @param response A pointer to a SoftwareSerial object for sending responses.
    */
    void controllerTurnRight(char command);
     
 /**
    * @brief Controls the car to turn right based on the given command.
    * @param command A character representing the command.
    * @param response A pointer to a SoftwareSerial object for sending responses.
    */
    void controllerTurnLeft(char command);
     /**
    * @brief Controls the car to turn left based on the given command.
    * @param command A character representing the command.
    * @param response A pointer to a SoftwareSerial object for sending responses.
    */
    void controllerRotationRight(char command);
    /**
    * @brief Controls the car to rotate right based on the given command.
    * @param command A character representing the command.
    * @param response A pointer to a SoftwareSerial object for sending responses.
    */
    void controllerRotationLeft(char command);
     /**
    * @brief Controls the car to rotate left based on the given command.
    * @param command A character representing the command.
    * @param response A pointer to a SoftwareSerial object for sending responses.
    */
    void controllerStopDirection(char command);
     /**
    * @brief Stops the car's current direction based on the given command.
    * @param command A character representing the command.
    * @param response A pointer to a SoftwareSerial object for sending responses.
    */
 
    void controllerStop(char command);
    /**
    * @brief Stops the car based on the given command.
    * @param command A character representing the command.
    * @param response A pointer to a SoftwareSerial object for sending responses.
    */
    void controllerServAxisY(char command);
     /**
    * @brief Controls the Y-axis of the servo based on the given command.
    * @param command A character representing the command.
    * @param response A pointer to a SoftwareSerial object for sending responses.
    */
    void controllerServAxisX(char command);
     /**
    * @brief Controls the X-axis of the servo based on the given command.
    * @param command A character representing the command.
    * @param response A pointer to a SoftwareSerial object for sending responses.
    */
};