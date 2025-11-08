#include <stdio.h>

int main() {
    int v[5] = {4, -2, 7, 0, 3};
    int i;
    
    int min = v[0];
   
    int pozMin = 0;

    for (i = 1; i < 5; i++) {
       
        if (v[i] < min) {
            min = v[i];
            pozMin = i;
        }
    }

    
    printf("Valoarea minima este %d la pozitia %d\n", min, pozMin);

    return 0;
}
