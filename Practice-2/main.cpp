#include <stdio.h>
#include <cmath>

int main()
{
    int x, y; int gotTheTarget = 0; 
    int iterator = 0;
    do {
        scanf("%i%i", &x, &y);
        float res = sqrt(x*x + y*y);
        if ( res >= 3 and res <= 5 )
        {
            gotTheTarget++;
        }
        iterator++;
    }while ( iterator < 5 );
    printf("Вы попали %i раз.", gotTheTarget);
}