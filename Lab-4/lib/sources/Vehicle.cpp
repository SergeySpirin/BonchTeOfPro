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

void Vehicle::setModel(string sModel)
{
    model = sModel;
}

void Vehicle::setManufactureDate(int sManufactureDate)
{
    manufactureDate = sManufactureDate;
}

void Vehicle::setCost(int sCost)
{
    cost = sCost;
}

string Vehicle::getManufactorer()
{
    return manufactorer;
}

string Vehicle::getModel()
{
    return model;
}

int Vehicle::getManufactureDate() 
{
    return manufactureDate;
}

int Vehicle::getCost()
{
    return cost;
}

void Vehicle::printItem(int colLen[8], int iterator) 
{
    cout << "Vehicle::ptintItem()";
}

void Vehicle::detailInfo() 
{
    cout << "Производитель -> " << manufactorer << endl
        << "Модель -> " << model << endl
        << "Год производства -> " << manufactureDate << endl
        << "Стоимость, $ -> " << cost << endl;
}

