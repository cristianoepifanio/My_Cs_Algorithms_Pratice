#include<stdio.h>

int main() {
    int rows, cols;

    // Read the dimensions of the matrices
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

    return 0;
}
