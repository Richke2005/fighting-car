#include "./car.hpp"

Car::Car() : battery(0.0), velocity(0.0), objectRadar(0.0) {}

void Car::setBridges(byte in1, byte in2, byte in3, byte in4){
    HBridgeMotor bridge1(in1, in2, in3, in4);
}

void Car::foward(){

}

void Car::backward(){
    
}