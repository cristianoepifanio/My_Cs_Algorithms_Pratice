#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(){
    /*Check if 2 tridimensional vectors are orthogonal */
    int i;
    int *A, *B;
    
    A = (int*) malloc(3 * sizeof(int));
    B = (int*) malloc(3 * sizeof(int)); 
    printf("\nTo check if 2 tridimensional vectors are orthogonal\n");
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
    int scalar_product = 0;
    for(i = 0; i < 3; i++) {
        scalar_product += A[i] * B[i];
    }
    printf("\n");
    if(scalar_product == 0) {
        printf("\nThe escalar product is %d, so, the vectors are orthogonal.\n", scalar_product);
    } else {
        printf("\nThe escalar product is %d, so, the vectors are not orthogonal.\n", scalar_product);
    }
    printf("\n");
    free(A);
    free(B);

    return 0;
    
}