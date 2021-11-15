#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include <string>

using namespace std;

class Car : public Vehicle
{
    public:
        Car(string, int, float, bool);
        ~Car();
        
        void setSeatHeatingValue(bool);
                
        bool getSeatHeatingValue();

    private:
        bool hasSeatHeating;
};

#endif
