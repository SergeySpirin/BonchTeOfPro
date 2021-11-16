#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include <string>

using namespace std;

class Car : public Vehicle
{
    public:
        Car(string, string, int, int, bool);
        ~Car();
        
        void setSeatHeatingValue(bool);
                
        bool getSeatHeatingValue();

        void printItem(int colLen[8], int iterator);

        void detailInfo();

    private:
        bool hasSeatHeating;
};

#endif
