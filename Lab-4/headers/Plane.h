#ifndef PLANE_H 
#define PLANE_H

#include "Vehicle.h"
#include <string>

using namespace std;

class Plane : public Vehicle
{
    public:
        Plane(string, int, float, int);
        ~Plane();
        
        void setEnginesCount(int);
                
        int getEnginesCount();

    private:
        int enginesCount;
};

#endif
