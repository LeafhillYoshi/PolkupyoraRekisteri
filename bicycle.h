// Bicycle.h
// Purpose: Header file for Bicycle class.
// This class is used to represent a bicycle object.

#ifndef BICYCLE_H
#define BICYCLE_H

#include <string>

class Bicycle
{
public:
	Bicycle();

	void setBrand(const std::string& brand);
	void setModel(const std::string& model);
	void setYear(int year);
	void setFrameSize(const std::string& frameSize);
	void setWheelSize(const std::string& wheelSize);
	void setWheelAmount(int wheelAmount);
	void setFrameNumber(const std::string& frameNumber);
	void setBikeType(const std::string& bikeType);

protected:
	std::string brand;
	std::string model;
	int year;
	std::string frameSize;
	std::string wheelSize;
	int wheelAmount;
	std::string frameNumber;
	std::string bikeType;
};
#endif // !BICYCLE_H
