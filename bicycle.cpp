// Bicycle.cpp
#include <iostream>
#include <string>
#include "bicycle.h"

// Constructor implementation
Bicycle::Bicycle() : brand(brand), model(model), year(year = 0),
    frameSize(frameSize), wheelSize(wheelSize),
    wheelAmount(2), frameNumber(frameNumber) {
    // Constructor body can be empty if only initializing member variables
}

// Setter methods implementation
void Bicycle::setBrand(const std::string& brand) {
    this->brand = brand;
}

void Bicycle::setModel(const std::string& model) {
    this->model = model;
}

void Bicycle::setYear(int year) {
    this->year = year;
}

void Bicycle::setFrameSize(const std::string& frameSize) {
    this->frameSize = frameSize;
}

void Bicycle::setWheelSize(const std::string& wheelSize) {
    this->wheelSize = wheelSize;
}

void Bicycle::setWheelAmount(int wheelAmount) {
    this->wheelAmount = wheelAmount;
}

void Bicycle::setFrameNumber(const std::string& frameNumber) {
    this->frameNumber = frameNumber;
}

void Bicycle::setBikeType(const std::string& bikeType) {
    this->bikeType = bikeType;
}