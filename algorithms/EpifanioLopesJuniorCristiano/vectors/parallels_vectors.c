#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
int main(){
    /* Check if 2 tridimensional vectors are parallel */
    int i;
    int *A, *B;
    bool parallel = true;
    float ratio;
    A = (int*) malloc(3 * sizeof(int));
    B = (int*) malloc(3 * sizeof(int)); 
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
    if(B[0] == 0) {
        if(A[0] != 0) {
            parallel = false;
        }
    } else {
        ratio = (float)A[0]/(float)B[0];
        for(i = 1; i < 3; i++) {
            if(B[i] == 0) {
                if(A[i] != 0) {
                    parallel = false;
                }
            } else {
                if(fabs(((float)A[i]/(float)B[i]) - ratio) > 0.00001) {
                    parallel = false;
                }
            }
        }
    }
    printf("\n");
    if(parallel) {
        printf("The vectors are parallel.\n");
    } else {
        printf("The vectors are not parallel.\n");
    }
    printf("\n");
    free(A);    
    free(B);
   
    return 0;
}