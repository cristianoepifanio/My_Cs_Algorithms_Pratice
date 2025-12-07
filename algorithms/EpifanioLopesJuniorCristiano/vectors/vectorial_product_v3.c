#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* Vectorial product of 2 tridimensional vectors */
    int i;
    int *A, *B, *C;
    A = (int*) malloc(3 * sizeof(int));
    B = (int*) malloc(3 * sizeof(int)); 
    C = (int*) malloc(3 * sizeof(int));
    printf("\nTo calculate the vectorial product between 2 tridimensional vectors\n");
    printf("Enter the 3 elements of vector A:\n");
    for(i = 0; i < 3; i++) {
        printf("type %dth cordinate: ", i+1);
        scanf("%d", &A[i]);
    }
    printf("Enter the 3 elements of vector B:\n");
    for(i = 0; i < 3; i++) {
        printf("type %dth cordinate: ", i+1);
        scanf("%d", &B[i]);
    }   
    C[0] = A[1]*B[2] - A[2]*B[1];
    C[1] = A[2]*B[0] - A[0]*B[2];
    C[2] = A[0]*B[1] - A[1]*B[0];
    printf("\n");
    printf("The vectorial product of the vectors is: (%d, %d, %d)\n", C[0], C[1], C[2]);
    printf("\n");
    free(A);    
    free(B);
    free(C);
   
    return 0;
}
