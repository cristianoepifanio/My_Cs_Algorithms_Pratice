#include <stdio.h>
#include <stdlib.h>

int main(){

    /* Subtraction of 2 n-dimensional vectors */
    int n, i;
    int *A, *B, *C; 
    printf("Enter the dimension of the vectors: ");
    scanf("%d", &n);    
    A = (int*) malloc(n * sizeof(int));
    B = (int*) malloc(n * sizeof(int));
    C = (int*) malloc(n * sizeof(int));
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
        C[i] = A[i] - B[i];
    }
    printf("\n");
    printf("The subtraction of the vectors (A - B) is: (");   
    for(i = 0; i < n; i++) {
        if(i != n-1) {
            printf("%d, ", C[i]);
        } else {
            printf("%d)\n", C[i]);
        }
    }
    printf("\n");
    free(A);
    free(B);
    free(C);
   
    return 0;
}