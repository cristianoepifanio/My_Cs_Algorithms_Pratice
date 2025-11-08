#include <stdio.h>

int main() {
    int v[5] = {4, -2, 7, 0, 3};
    int i;
    int max = v[0];

    int pozMax = 0;
    

    for (i = 1; i < 5; i++) {
        if (v[i] > max) {
            max = v[i];
            pozMax = i;
        }
    }

    printf("Valoarea maxima este %d la pozitia %d\n", max, pozMax);
    

    return 0;
}
