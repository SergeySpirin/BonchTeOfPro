#include <stdio.h>

int main(){
    int a, b, h;

    for (int i = 0; i < 3; i++){
        scanf("%i%i%i", &a, &b, &h);
        printf("Площадь = %.1f\n", float((a + b) * h / 2));
    }

    return 0;
}