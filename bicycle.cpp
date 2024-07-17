// Bicycle.cpp
#include <iostream>
#include <string>
#include "bicycle.h"

using namespace std;

// Constructor implementation
Bicycle::Bicycle() : brand(brand), model(model), year(year = 0),
    frameSize(frameSize), wheelSize(wheelSize),
    wheelAmount(2), frameNumber(frameNumber) {}

// Setter methods implementation
void Bicycle::setId(const std::string& id) {
	this->id = id;
}

string Bicycle::getId() const {
	return id;
}

void Bicycle::setBrand(const std::string& brand) {
    this->brand = brand;
}

string Bicycle::getBrand() const {
    return brand;
}

void Bicycle::setModel(const std::string& model) {
    this->model = model;
}

string Bicycle::getModel() const {
    return model;
}

void Bicycle::setYear(int year) {
    this->year = year;
}


int Bicycle::getYear() const {
    return year;
}

void Bicycle::setFrameSize(const std::string& frameSize) {
    this->frameSize = frameSize;
}

string Bicycle::getFrameSize() const {
    return frameSize;
}

void Bicycle::setWheelSize(const std::string& wheelSize) {
    this->wheelSize = wheelSize;
}

string Bicycle::getWheelSize() const {
    return wheelSize;
}

void Bicycle::setWheelAmount(int wheelAmount) {
    this->wheelAmount = wheelAmount;
}

int Bicycle::getWheelAmount() const {
    return wheelAmount;
}

void Bicycle::setFrameNumber(const std::string& frameNumber) {
    this->frameNumber = frameNumber;
}

string Bicycle::getFrameNumber() const {
    return frameNumber;
}

void Bicycle::setBikeType(const std::string& bikeType) {
    this->bikeType = bikeType;
}

string Bicycle::getBikeType() const {
    return bikeType;
}