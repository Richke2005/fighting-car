#include "./car.hpp"

Car::Car() : battery(0.0), velocity(0.0), objectRadar(0.0) {}

void Car::setBridges(HBridgeMotor* bridge1, HBridgeMotor* bridge2){
    bridge1->initialize();
}

void Car::foward(){

}

void Car::backward(){
    
}