#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>        

void escalar_product_v3(void) {
    int x1, x2, y1, y2, z1, z2;
    printf("Enter coordinates of first vector (x1 y1 z1): ");
    scanf("%d %d %d", &x1, &y1, &z1);
    printf("Enter coordinates of second vector (x2 y2 z2): ");
    scanf("%d %d %d", &x2, &y2, &z2);
    int scalar_product = x1 * x2 + y1 * y2 + z1 * z2;
    printf("\n");
    printf("Scalar product: %d\n", scalar_product);
    printf("\n");
};

void escalar_product_n(void) {
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
};

    void subtraction_Vn(void) {
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
    };

    void orthogonal_vectors_v3(void) {
        /*Check if 2 tridimensional vectors are orthogonal */
    int i;
    int *A, *B;
    // bool orthogonal = true;
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
    int scalar_product = 0;
    for(i = 0; i < 3; i++) {
        scalar_product += A[i] * B[i];
    }
    printf("\n");
    if(scalar_product == 0) {
        printf("The vectors are orthogonal.\n");
    } else {
        printf("The vectors are not orthogonal.\n");
    }
    printf("\n");
    free(A);
    free(B);

    };

int main()
{
    int opt;
    printf("\n");
    printf("Select an option:\n1. Escalar producto for a tridimensional vector\n");
    printf("Select an option:\n2. Escalar producto for a n-dimensional vector\n");
    printf("Select an option:\n3. Subtraction between 2 vectors n-dimensional\n");
    printf("Select an option:\n4. Check if 2 tridimensional vectors are orthogonal\n");
    printf("Select an option:\n5. \n");
    printf("Select an option:\n6. \n");
    printf("Select an option:\n7. \n");
    printf("Select an option:\n8. \n");
    printf("Select an option:\n9. \n");
    printf("Select an option:\n10. \n");
    printf("0. Exit\n");
    printf("\n");
    scanf("%d", &opt);
    do
    {
        switch (opt)
        {
        case 1:
            escalar_product_v3();
            break;
        case 2:
            escalar_product_n();
            break;
        case 3:
            subtraction_Vn();
            break;
        case 4:
            orthogonal_vectors_v3();
            break;
        default:
            break;
        }
        printf("Select an option:\n1. Option One\n2. Option Two\n3. Option Three\n0. Exit\n");
        scanf("%d", &opt);
    } while (opt != 0);



    return 0;
}