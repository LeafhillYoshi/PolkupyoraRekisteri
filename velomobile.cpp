// velomobile.cpp
#include <iostream>
#include <string>
#include "velomobile.h"

using namespace std;

// Constructor implementation
Velomobile::Velomobile() : Bicycle() 
{
	std::cout << "Velomobile constructor" << std::endl;
}

void Velomobile::setWheelAmount(int wheelAmount)
{
	if(wheelAmount >= 3 && wheelAmount <= 4)
	{
		this->wheelAmount = wheelAmount;
	}
	else
	{
		std::cout << "Velomobiilissa on oltava 3 tai 4 py�r��" << std::endl;
	}
}

void Velomobile::setBikeType(std::string bikeType)
{
	this->bikeType = bikeType;
}
