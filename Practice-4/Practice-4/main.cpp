#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n = 80000;
    int x0 = -5;
    int x1 = 5;
    float x,y;
    float h =(float)(x1-x0)/(n-1);
    float s = 0;
    for (int i = 1; i <= n; i++)
    {
        x = x0 + ( i - 1 ) * h;
        y = x * x;
        s = s + y * h;
    };
    cout << s << endl;
}
