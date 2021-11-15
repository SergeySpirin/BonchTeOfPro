#include "../headers/Vehicle.h"

#include <iostream> 
#include <string>

using namespace std;

Vehicle::Vehicle() {};

Vehicle::~Vehicle() {};

void Vehicle::setManufactorer(string sManufactorer)
{
    manufactorer = sManufactorer;
}

void Vehicle::setManufactureDate(int sManufactureDate)
{
    manufactureDate = sManufactureDate;
}

void Vehicle::setCost(float sCost)
{
    cost = sCost;
}

string Vehicle::getManufactorer()
{
    return manufactorer;
}

int Vehicle::getManufactureDate() 
{
    return manufactureDate;
}

float Vehicle::getCost()
{
    return cost;
}


