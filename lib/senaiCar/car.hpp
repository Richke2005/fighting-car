#pragma once
#include <SoftwareSerial.h>
#include "../dcMotors/hBridgeMotor.hpp"
#include "../../include/config.hpp"

struct batteryLeds{
    uint8_t greenLed;
    uint8_t yellowLed;
    uint8_t redLed;
};


class Car {
    protected: 
    uint8_t pinBattery;
    float battery;
    float velocity;
    bool connectionStatus;
    float objectRadar;
    batteryLeds leds;
    
    public:
    /**
     * @class Car
     * @brief A class to represent a car with various functionalities such as battery management, velocity tracking, and connection status.
     * 
     * The Car class provides methods to manage the car's battery, control battery indicator LEDs, and retrieve information about the car's battery and velocity.
     */

    /**
     * @brief Default constructor for the Car class.
     */
    Car();

    /**
     * @brief Constructor for the Car class with a specified battery pin.
     * @param pin The pin number to which the battery is attached.
     */
    Car(uint8_t pin);

    /**
     * @brief Attach the battery to a specified pin.
     * @param pinBattery The pin number to which the battery is attached.
     */
    void attachBattery(uint8_t pinBattery);

    /**
     * @brief Attach LEDs to specified pins for battery status indication.
     * @param redLed The pin number for the red LED.
     * @param yellowLed The pin number for the yellow LED.
     * @param greenLed The pin number for the green LED.
     */
    void attachLeds(uint8_t redLed, uint8_t yellowLed, uint8_t greenLed);

    /**
     * @brief Control the battery indicator LEDs based on the battery status.
     */
    void controlBatteryLeds();

    /**
     * @brief Get the current battery level.
     * @return The current battery level as a float.
     */
    float getBattery();

    /**
     * @brief Get the current battery level as a percentage.
     * @return The current battery level as an unsigned integer percentage.
     */
    unsigned int getBatteryToPercent();

    /**
     * @brief Get the current velocity of the car.
     * @return The current velocity as an integer.
     */
    int getVelocity();
};