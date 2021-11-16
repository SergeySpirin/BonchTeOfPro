#ifndef PLANE_H 
#define PLANE_H

#include "Vehicle.h"
#include <string>

using namespace std;

class Plane : public Vehicle
{
    public:
        Plane(string, string, int, int, int);
        ~Plane();
        
        void setEnginesCount(int);
                
        int getEnginesCount();

        void printItem(int colLen[8], int iterator);

        void detailInfo();

    private:
        int enginesCount;
};

#endif
