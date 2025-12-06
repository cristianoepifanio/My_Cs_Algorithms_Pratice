#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>        

void escalar_product_v3(void) {
    int x1, x2, y1, y2, z1, z2;
    printf("To calculate the product escalar between 2 tridimensional vectors\n");
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

    printf("To calculate the product escalar between 2 n-dimensional vectors\n");
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
    printf("To calculate the subtraction between 2 n-dimensional vectors (A - B)\n");
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

    printf("To check if 2 tridimensional vectors are orthogonal\n");
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
    void vectorial_product_vn(void) {
        /* Vectorial product of n dimensional vectors */
    int i, n;
    int *A, *B, *C;
    printf("To calculate the vectorial product between 2 n-dimensional vectors\n");
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
    printf("\n");
    free(A);}   
    
    void matrix_addition(void) {
         // Read the dimensions of the matrices
    int rows, cols;
    printf("To perform the addition between 2 matrices\n");
    printf("Enter number of rows and columns: \n");
    printf("rows: ");
    scanf("%d", &rows);
    printf("columns: ");
    scanf("%d",&cols);
    
    int matrixA[rows][cols];
    int matrixB[rows][cols];
    int result[rows][cols];
    
    // Read first matrix
    printf("Enter elements of first matrix:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("Enter the element a%d%d: ", i + 1, j + 1);
            scanf("%d", &matrixA[i][j]);
        }
    }
    
    // Read second matrix
    printf("Enter elements of second matrix:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("Enter the element b%d%d: ", i + 1, j + 1);
            scanf("%d", &matrixB[i][j]);
        }
    }

    // Perform matrix addition
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    // Print the result matrix
    printf("Resultant Matrix after Addition:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    };
    void matrix_multiplication_by_escalar(void) {
        int rows, cols;

    // Read the dimensions of the matrices
    printf("To perform the multiplication of a matrix by a escalar\n");
    printf("Enter number of rows and columns: \n");
    printf("rows: ");
    scanf("%d", &rows);
    printf("columns: ");
    scanf("%d",&cols);


    int matrixA[rows][cols];
    int result[rows][cols];
    int scalar;

    // Read the matrix
    printf("Enter elements of matrix:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
             printf("Enter the element a%d%d: ", i + 1, j + 1);
            scanf("%d", &matrixA[i][j]);
        }
    }

    // Read the scalar value    
    printf("Enter the scalar value: ");
    scanf("%d", &scalar);
    
    // Perform scalar multiplication
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] * scalar;
        }
    }

    // Print the result matrix
    printf("Resultant Matrix after Addition:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    };

    void matrix_rasing_to_a_power(void) {
        int rows, cols;
        // Read the dimensions of the matrices
    printf("To perform the raising of a matrix to a power\n");
    printf("Enter number of rows and columns: \n");
    printf("rows: ");
    scanf("%d", &rows);
    printf("columns: ");
    scanf("%d",&cols);


    int matrixA[rows][cols];
    int result[rows][cols];
    int scalar;

    // Read the matrix
    printf("Enter elements of matrix:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
             printf("Enter the element a%d%d: ", i + 1, j + 1);
            scanf("%d", &matrixA[i][j]);
        }
    }

    // Read the scalar value    
    printf("Enter the scalar value: ");
    scanf("%d", &scalar);
    
    // Perform scalar multiplication
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = pow(matrixA[i][j],scalar);
        }
    }

    // Print the result matrix
    printf("Resultant Matrix after Addition:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    };
    void multiplication_between_two_matrix(void) {
       int rowsA=10,colsA=10;
    int rowsB=10,colsB=10;
    
    
    // Read the dimensions of the matrix A
    printf("To perform the multiplication between 2 matrices\n");
    printf("Enter number of rows and columns for matrix A: \n");
    printf("rows: ");
    scanf("%d", &rowsA);
    printf("columns: ");
    scanf("%d",&colsA);
    
    int matrixA[rowsA][colsA];
    
    // Read first matrix
    printf("Enter elements of first matrix:\n");
    for(int i = 0; i < rowsA; i++) {
        for(int j = 0; j < colsA; j++) {
            printf("Enter the element a%d%d: ", i + 1, j + 1);
            scanf("%d", &matrixA[i][j]);
        }
    }
    

    // Read the dimensions of the matrix B
    printf("Enter number of rows and columns for matrix B: \n");
    printf("rows: ");       
    scanf("%d", &rowsB);
    while (colsA != rowsB)
    {
        printf("The number of column of first matrix (%d) must to be equal to row of second.\n", colsA);
        printf("Enter rows and columns for matrix B again: \n");    
        printf("rows: ");       
        scanf("%d", &rowsB);

    }
    
    printf("columns: ");
    scanf("%d",&colsB);

    
    int matrixB[rowsB][colsB];
    
    // Read second matrix
    printf("Enter elements of second matrix:\n");
    for(int i = 0; i < rowsB; i++) {
        for(int j = 0; j < colsB; j++) {
            printf("Enter the element b%d%d: ", i + 1, j + 1);
            scanf("%d", &matrixB[i][j]);
        }
    }
    int result[rowsA][colsB]; 
     // Perform matrix multiplication
    for(int i = 0; i < rowsA; i++) {
        for(int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for(int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    // Print the result matrix
    printf("Resultant Matrix after Multiplication:\n");
    for(int i = 0; i < rowsA; i++) {
        for(int j = 0; j < colsB; j++) {
            printf("%d ",  result[i][j]);
        }
        printf("\n");
    }
    };
    void transposed_matrix(void) {
        int rows, cols;
        // Read the dimensions of the matrix
    printf("Enter number of rows and columns for the matrix: \n");
    printf("rows: ");
    scanf("%d", &rows);
    printf("columns: ");
    scanf("%d",&cols);
    
    int matrix[rows][cols];
    
    // Read matrix elements
    printf("Enter elements of the matrix:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("Enter the element a%d%d: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int transposed[cols][rows];
    
    // Compute the transpose of the matrix
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    
    // Print the transposed matrix
    printf("Transposed Matrix:\n");
    for(int i = 0; i < cols; i++) {
        for(int j = 0; j < rows; j++) {
            printf("%d ", transposed[i][j]);
        }   
        printf("\n");
    }
    };
int main()
{
    int opt;
    printf("\n");
    printf("Select an option:\n1. Escalar producto for a tridimensional vector\n");
    printf("2. Escalar producto for a n-dimensional vector\n");
    printf("3. Subtraction between 2 vectors n-dimensional\n");
    printf("4. Check if 2 tridimensional vectors are orthogonal\n");
    printf("5. Vectorial product between 2 n-dimensional vectos \n");
    printf("6. Addition between 2 matrix\n");
    printf("7. Multiplicate a matrix times an escalar\n");
    printf("8. Rise a matrix by a power\n");
    printf("9. Multiplicate 2 matrix\n");
    printf("10. Transpose a matrix\n");
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
        case 5:
            vectorial_product_vn();
            break;
        case 6:
            matrix_addition();
            break;
        case 7:
            matrix_multiplication_by_escalar();
            break;
        case 8:
            matrix_rasing_to_a_power();
            break;
        case 9:
            multiplication_between_two_matrix();
            break;
        case 10:
            transposed_matrix();    
            break;
        default:
            printf("unfortunately this option is not disponible, try something between 1-10.\n");
            break;
        }
        if (opt!=0)
        {
             printf("Do you want do another option? If no, type: \n0. Exit\n");
            scanf("%d", &opt);
        }
        
       
    } while (opt != 0);



    return 0;
}