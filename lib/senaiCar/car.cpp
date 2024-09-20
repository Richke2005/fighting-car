#include "./car.hpp"

Car::Car() : battery(0.0), velocity(0.0), objectRadar(0.0) {}

void Car::foward(HBridgeMotor* motor1, HBridgeMotor* motor2){
    motor1->setMotorA(true, 1);
    motor2->setMotorB(true, 1);
}

void Car::backward(HBridgeMotor* motor1, HBridgeMotor* motor2){
    motor1->setMotorA(true, 2);
    motor2->setMotorB(true, 2);
}