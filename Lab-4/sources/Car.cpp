#include "../headers/Car.h"

#include <iostream> 
#include <string>

using namespace std;

Car::Car(string sManufactorer, int sManufactorerDate, float sCost, bool sSeatHeatingValue)
{
    manufactorer = sManufactorer;
    manufactureDate = sManufactorerDate;
    cost = sCost;
    hasSeatHeating = sSeatHeatingValue;
}

Car::~Car() {}

void Car::setSeatHeatingValue(bool sSeatHeatingValue)
{
    hasSeatHeating = sSeatHeatingValue;
}

bool Car::getSeatHeatingValue()
{
    return hasSeatHeating;
}    
