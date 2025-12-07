#include <stdio.h>

int main() {
    int rows, cols;

    printf("To calculate the multiplying of lower triangle elements of a square matrix\n");    
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    while (cols != rows)
    {
        printf("The matrix must to be square.\n");
        printf("Enter number of columns for matrix again: \n");    
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
    
    int mult = 1;
    
    // Sum lower triangle elements (where i >= j)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i >= j) {
                mult *= matrix[i][j];
            }
        }
    }
    
    printf("multiplying of lower triangle elements: %d\n", mult);
    
    return 0;
}