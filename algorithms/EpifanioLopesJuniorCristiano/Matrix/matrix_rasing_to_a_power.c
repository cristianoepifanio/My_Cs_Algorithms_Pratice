#include<stdio.h>
#include<math.h>

int main() {
    int rows, cols;

    // Read the dimensions of the matrices
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
    printf("Resultant Matrix after to be raised by a power:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}