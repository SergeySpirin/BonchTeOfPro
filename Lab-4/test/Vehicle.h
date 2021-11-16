#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

using namespace std;

class Vehicle
{
    public:
        Vehicle();
        ~Vehicle();
        
        void setManufactorer(string);
        void setModel(string);
        void setManufactureDate(int);
        void setCost(int);
        
        string getManufactorer();
        string getModel();
        int getManufactureDate();
        int getCost();

        virtual void printItem(int colLen[8], int iterator);
        virtual void detailInfo();

    protected:
        string manufactorer;
        string model;
        int manufactureDate;
        int cost;
};

#endif
