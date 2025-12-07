#include <stdio.h>

int main() {
    int rows, cols;
    
    printf("\nTo calculate the sum of the upper triangle elements of a square matrix\n");
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    while (cols != rows)
    {
        printf("The matrix must to be square.\n");
        printf("Enter columns for matrix again: \n");    
        printf("columns: ");       
        scanf("%d", &cols);

    }
        
    int matrix[rows][cols];
    
    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
             printf("Enter the element a%d%d: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int sum = 0;
    
    // Sum lower triangle elements (where i <= j)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i <= j) {
                sum += matrix[i][j];
            }
        }
    }
    
    printf("Sum of upper triangle elements: %d\n", sum);
    
    return 0;
}