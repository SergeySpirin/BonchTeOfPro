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
        void setManufactureDate(int);
        void setCost(float);
        
        string getManufactorer();
        int getManufactureDate();
        float getCost();

        virtual void printItem();

    protected:
        string manufactorer;
        int manufactureDate;
        float cost;
};

#endif
