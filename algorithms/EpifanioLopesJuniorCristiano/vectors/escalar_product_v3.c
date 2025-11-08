#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* Scala product of 2 tridimensional vectors */
    int x1, x2, y1, y2, z1, z2;  
     printf("Enter coordinates of first vector (x1 y1 z1): ");
    scanf("%d %d %d", &x1, &y1, &z1);
    printf("Enter coordinates of second vector (x2 y2 z2): ");
    scanf("%d %d %d", &x2, &y2, &z2);
    int scalar_product = x1 * x2 + y1 * y2 + z1 * z2;
    printf("Scalar product: %d\n", scalar_product);
   
    return 0;
}
