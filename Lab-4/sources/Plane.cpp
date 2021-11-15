#include "../headers/Plane.h"

#include <iostream> 
#include <string>

using namespace std;

Plane::Plane(string sManufactorer, int sManufactorerDate, float sCost, int sEnginesCount)
{
    manufactorer = sManufactorer;
    manufactureDate = sManufactorerDate;
    cost = sCost;
    enginesCount = sEnginesCount;
}

Plane::~Plane() {}

void Plane::setEnginesCount(int sEnginesCount)
{
    enginesCount = sEnginesCount;
}

int Plane::getEnginesCount()
{
    return enginesCount;
}
