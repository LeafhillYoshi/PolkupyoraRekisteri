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

	void setId(const std::string& id);
	std::string getId() const;
	void setBrand(const std::string& brand);
	std::string getBrand() const;
	void setModel(const std::string& model);
	std::string getModel() const;
	void setYear(int year);
	int getYear() const;
	void setFrameSize(const std::string& frameSize);
	std::string getFrameSize() const;
	void setWheelSize(const std::string& wheelSize);
	std::string getWheelSize() const;
	void setWheelAmount(int wheelAmount);
	int getWheelAmount() const;
	void setFrameNumber(const std::string& frameNumber);
	std::string getFrameNumber() const;
	void setBikeType(const std::string& bikeType);
	std::string getBikeType() const;

protected:
	std::string id;
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
