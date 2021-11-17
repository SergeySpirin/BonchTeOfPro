#include <iostream>
#include <iomanip>
#include <string>

#include "./headers/Vehicle.h"
#include "./headers/Car.h"
#include "./headers/Plane.h"

using namespace std;

int getManufactorerMaxLen(Vehicle** pointer, int count);

int getModelMaxLen(Vehicle** pointer, int count);

int getCostMaxLen(Vehicle** pointer, int count);

void printTable(Vehicle** pointer, int count)
{
    int colLen[8]; 
    colLen[0] = 2; 
    colLen[1] = 9; 
    colLen[2] = getManufactorerMaxLen(pointer, count);
    colLen[3] = getModelMaxLen(pointer, count);
    colLen[4] = 17;
    colLen[5] = getCostMaxLen(pointer, count); 
    colLen[6] = 14; 
    colLen[7] = 15; 
    
    cout << setw(colLen[0]) << left << "#" 
        << setw(colLen[1]) << "Vehicle" 
        << setw(colLen[2]) << "Manufactorer" 
        << setw(colLen[3]) << "Model" 
        << setw(colLen[4]) << "Manufature Year" 
        << setw(colLen[5]) << "Cost, $" 
        << setw(colLen[6]) << "Seat Heating" 
        << setw(colLen[7]) << "Engines Count" << endl;

    cout << setw(colLen[0]) << left << "-" 
        << setw(colLen[1]) << "-------" 
        << setw(colLen[2]) << "------------" 
        << setw(colLen[3]) << "-----" 
        << setw(colLen[4]) << "---------------" 
        << setw(colLen[5]) << "-------" 
        << setw(colLen[6]) << "------------" 
        << setw(colLen[7]) << "-------------" << endl;

    for (int i = 0; i < count; i++)
    {
        pointer[i]->printItem(colLen, i);
    }
    cout << endl;
}

void getAndPrintTheNewest(Vehicle** pointer, int count)
{
    int temp = 0;
    Vehicle* theMostExpensive;
    for (int i = 0; i < count; i++)
    {
        int year = pointer[i]->getManufactureDate();
        if (year > temp)
        {
            temp = year;
            theMostExpensive = pointer[i];
        }
    }
    cout << "Ифнормация о самом новом транспорте:" << endl << endl;
    theMostExpensive->detailInfo();
};

void changeItem(Vehicle* item, int index)
{
    string sManufactorer, sModel, sSeatHeatingValueText;
    int sManufactureDate, sCost, sEnginesCount;
    bool sSeatHeatingValue;
    cout << "Ведите производителя транспортного средства" << endl << ">" << endl;
    cin >> sManufactorer;
    cout << "Ведите модель транспортного средства" << endl << ">" << endl;
    cin >> sModel;
    cout << "Ведите год выпуска транспортного средства" << endl << ">" << endl;
    cin >> sManufactureDate;
    cout << "Ведите цену транспортного средства" << endl << ">" << endl;
    cin >> sCost;
    item -> setManufactorer(sManufactorer); 
    item -> setModel(sModel);
    item -> setManufactureDate(sManufactureDate);
    item -> setCost(sCost);
    if (index < 4)
    {
        cout << "Есть ли подогрев сидений?" << endl << ">";
        cin >> sSeatHeatingValueText;
        sSeatHeatingValue = (sSeatHeatingValueText == "yes" || sSeatHeatingValueText == "y" || sSeatHeatingValueText == "да" || sSeatHeatingValueText == "Да")
        ? true : false;
        ((Car*)item) -> setSeatHeatingValue(sSeatHeatingValue);
    }
    else
    {
        cout << "Сколько двигателей?" << endl << ">" << endl;
        cin >> sEnginesCount;
        ((Plane*)item) -> setEnginesCount(sEnginesCount);
    }

}

int main()
{
    Car BMW("BMW", "320i", 2019, 96000, true);
    Car Hellcat("Dodge", "Challenger Hellcat", 2020, 199000, true);
    Car Mustang("Ford", "Mustang", 2016, 34999, false); 

    Plane Boeing("Boeing", "737", 1997, 68000000, 2); 
    Plane F_16("General Dynamics", "F-16", 1998, 34000000, 2);
    Plane Douglas("Douglas Aircraft Company", "DC-4", 1946, 5000000, 4);

    int items_count = 6;
    Vehicle* vehicles[items_count];
    
    vehicles[0] = &BMW;
    vehicles[1] = &Hellcat;
    vehicles[2] = &Mustang;
    vehicles[3] = &Boeing;
    vehicles[4] = &F_16;
    vehicles[5] = &Douglas;

    int activity;
    int rowToShow, rowToChange;
    bool Continue = true;

    system("clear");
    printTable(vehicles, items_count);

    do
    {
        cout << "Что дальше: " << endl 
             << "[1] Показать информацию о ТС" << endl
             << "[2] Изменить ТС" << endl
             << "[3] Вывести информацию о самом новом ТС" << endl
             << "[4] Выйти" << endl << ":";
        cin >> activity;
        switch (activity){
            case 1:
            {
                cout << endl;
                cout << "Какое ТС показать? -> ";
                cin >> rowToShow;
                system("clear");
                printTable(vehicles, items_count);
                vehicles[rowToShow-1] -> detailInfo();
                break;
            }
            case 2:
            { 
                cout << endl;
                cout << "Какую строку менять? -> ";
                cin >> rowToChange;
                changeItem(vehicles[rowToChange-1], rowToChange);
                system("clear");
                printTable(vehicles, items_count);
                break;
            }
            case 3:
            { 
                system("clear");
                printTable(vehicles, items_count);
                getAndPrintTheNewest(vehicles, items_count);
                break;
            }
            case 4:
            {
                Continue = false;
                break;
            }
            default: 
                system("clear");
                break;
        }
    }
    while(Continue);
    system("clear");
}

int getManufactorerMaxLen(Vehicle** pointer, int count)
{
    int length = 12;
    for (int i = 0; i < count; i++)
    {
        int curLen = pointer[i]->getManufactorer().length();
        if (curLen > length)
        {
            length = curLen;
        }
    }
    return length + 2;
}

int getModelMaxLen(Vehicle** pointer, int count)
{
    int length = 5;
    for (int i = 0; i < count; i++)
    {
        int curLen = pointer[i]->getModel().length();
        if (curLen > length)
        {
            length = curLen;
        }
    }
    return length + 2;
}

int getCostMaxLen(Vehicle** pointer, int count)
{
    int length = 3;
    for (int i = 0; i < count; i++)
    {
        int curLen = to_string(pointer[i]->getCost()).length();
        if (curLen > length)
        {
            length = curLen;
        }
    }
    return length + 2;
}
