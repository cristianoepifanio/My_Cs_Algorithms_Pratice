#include <stdio.h>
#include <stdlib.h>
void sum(void)
{
    int a, b, sum;
    printf("Enter two integers to sum: ");
    scanf("%d %d", &a, &b);
    sum = a + b;
    printf("Sum: %d\n", sum);
};
void subt(void)
{
    int a, b, subt;
    printf("Enter two integers to subtract (a - b): ");
    scanf("%d %d", &a, &b);
    subt = a - b;
    printf("Subtraction: %d\n", subt);
};
int main()
{

    int choice;
    while (choice != 0)
    {
        printf("Choose an operation:\n");
        printf("1. Scalar Product of n-dimensional Vectors\n");
        printf("2. Subtraction of n-dimensional Vectors\n");
        printf("Enter your choice (1 or 2): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("Every thing is done.\n");
            break;
        case 1:
            sum();
            break;
        case 2:
            subt();
            break;
        default:
            printf("Invalid choice. Please select 1 or 2.\n");
            break;
        }
    }
    return 0;
}