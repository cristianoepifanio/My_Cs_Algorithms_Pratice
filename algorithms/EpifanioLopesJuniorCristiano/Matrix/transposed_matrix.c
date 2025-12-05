#include<stdio.h>

int main() {
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
    return 0;
        }
    
                
