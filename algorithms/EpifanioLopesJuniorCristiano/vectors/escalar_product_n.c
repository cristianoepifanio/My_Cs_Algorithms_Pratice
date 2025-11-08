#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* Scala product of 2 n-dimensional vectors */
    int n, i;
    int *A, *B; 
    int scalar_product = 0;
    printf("Enter the dimension of the vectors: ");
    scanf("%d", &n);    
    A = (int*) malloc(n * sizeof(int));
    B = (int*) malloc(n * sizeof(int));
    printf("Enter the %d elements of vector A:\n",n);
    for(i = 0; i < n; i++) {
        printf("Type the %dth cordinate: ", i+1);
        scanf("%d", &A[i]);
    }
    printf("Enter the %d elements of vector B:\n",n);
    for(i = 0; i < n; i++) {
        printf("Type the %dth cordinate: ", i+1);
        scanf("%d", &B[i]);
    }
    for(i = 0; i < n; i++) {
        scalar_product += A[i] * B[i];
    }
    printf("\n");
    printf("The scalar product of the vectors is: %d\n", scalar_product);
    printf("\n");
    free(A);
    free(B);
   
    return 0;
}
