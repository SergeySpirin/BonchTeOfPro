#include "../headers/Car.h"

#include <iostream> 
#include <string>
#include <iomanip>

using namespace std;

Car::Car(string sManufactorer, string sModel, int sManufactorerDate, int sCost, bool sSeatHeatingValue)
{
    manufactorer = sManufactorer;
    model = sModel; 
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

void Car::printItem(int colLen[8], int iterator)
{
    string sh = hasSeatHeating ? "✓   " : "×   ";
    int colLenTick = hasSeatHeating ? 16 : 15;
    cout << setw(colLen[0]) << left << iterator + 1 
        << setw(colLen[1]) << "Car" 
        << setw(colLen[2]) << manufactorer
        << setw(colLen[3]) << model 
        << setw(colLen[4]) << manufactureDate 
        << setw(colLen[5]) << cost
        << setw(colLenTick) << sh
        << setw(colLen[7]) << "-" << endl;
}

void Car::detailInfo()
{
    string sh = hasSeatHeating ? "✓" : "×";
    cout << "Транспортное средство -> Автомобиль" << endl
        << "Производитель -> " << manufactorer << endl
        << "Модель -> " << model << endl
        << "Год производства -> " << manufactureDate << endl
        << "Стоимость, $ -> " << cost << endl
        << "Подогрев сидений -> " << sh << endl << endl;
}