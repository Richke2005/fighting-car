#pragma once

class Car {
    protected: 
    float battery = 0;
    float velocity = 0;
    bool connectionStatus = false;
    float objectRadar;

    public:
    void setBattery();
    void setVelocity();
}