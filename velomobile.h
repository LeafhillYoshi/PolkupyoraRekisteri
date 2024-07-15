// Velomobile.h
// Purpose: Header file for Velomobile class.
// This class is used to represent a velomobile object, a variant of the bicycle.

#ifndef VELOMOBILE_H
#define VELOMOBILE_H

#include "bicycle.h"
#include <string>

class Velomobile : public Bicycle
{
public:
    // Constructor
    Velomobile() {}
    void setWheelAmount(int wheelAmount);
    void setBikeType(std::string bikeType);

protected:
    
};

#endif // VELOMOBILE_H