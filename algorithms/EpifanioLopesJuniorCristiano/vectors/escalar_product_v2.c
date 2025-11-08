#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* Scala product of 2 bidimensional vectors */
    int x1, x2, y1, y2;  
    printf("Enter coordinates of first vector (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter coordinates of second vector (x2 y2): ");
    scanf("%d %d", &x2, &y2);
    int scalar_product = x1 * x2 + y1 * y2;
    printf("Scalar product: %d\n", scalar_product);
    return 0;
}
