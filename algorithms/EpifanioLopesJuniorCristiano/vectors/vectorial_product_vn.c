#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* Vectorial product of n dimensional vectors */
    int i, n;
    int *A, *B, *C;
    printf("Enter the dimension n of the vectors:\n");
    scanf("%d", &n);    
    A = (int*) malloc(n * sizeof(int)); 
    B = (int*) malloc(n * sizeof(int));
    C = (int*) malloc(n * sizeof(int)); 
    printf("Enter the %d elements of vector A:\n", n);
    for(i = 0; i < n; i++) {
        printf("type %dth cordinate: ", i+1);
        scanf("%d", &A[i]);
    }   
    printf("Enter the %d elements of vector B:\n", n);
    for(i = 0; i < n; i++) {
        printf("type %dth cordinate: ", i+1);
        scanf("%d", &B[i]);
    }   
    for(i = 0; i < n; i++) {
        C[i] = A[(i+1)%n]*B[(i+2)%n] - A[(i+2)%n]*B[(i+1)%n];
    }
    printf("\n");
    printf("The vectorial product of the vectors is: (");   
    for(i = 0; i < n; i++) {
        if(i != n-1) {
            printf("%d, ", C[i]);
        } else {
            printf("%d)\n", C[i]);
        }
    }
    
   
   
    return 0;
}
