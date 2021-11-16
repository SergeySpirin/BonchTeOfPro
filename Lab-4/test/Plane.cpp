#include "Plane.h"

#include <iostream> 
#include <string>
#include <iomanip>

using namespace std;

Plane::Plane(string sManufactorer, string sModel, int sManufactorerDate, int sCost, int sEnginesCount)
{
    manufactorer = sManufactorer;
    model = sModel;
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

void Plane::printItem(int colLen[8], int iterator)
{
    cout << setw(colLen[0]) << left << iterator + 1
        << setw(colLen[1]) << "Plane" 
        << setw(colLen[2]) << manufactorer
        << setw(colLen[3]) << model 
        << setw(colLen[4]) << manufactureDate 
        << setw(colLen[5]) << cost
        << setw(colLen[6])  << "-" 
        << setw(colLen[7]) << enginesCount << endl;
}

void Plane::detailInfo()
{
    cout << "Транспортное средство -> Самолет" << endl
        << "Производитель -> " << manufactorer << endl
        << "Модель -> " << model << endl
        << "Год производства -> " << manufactureDate << endl
        << "Стоимость, $ -> " << cost << endl
        << "Количество двигателей -> " << enginesCount << endl << endl;
}