#include<stdio.h>

int main() {
    int rowsA,colsA;
    int rowsB,colsB;
    
    
    // Read the dimensions of the matrix A
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
      
    
   
    return 0;
}
