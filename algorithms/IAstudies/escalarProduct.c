#include <stdio.h>
#include <stdlib.h>

/* Compute dot (scalar) product of two vectors of length n */
double dot_product(const double *a, const double *b, size_t n) {
    double sum = 0.0;
    for (size_t i = 0; i < n; ++i) sum += a[i] * b[i];
    return sum;
}

int main(void) {
    size_t n;

    /* Read vector length */
    printf("Enter vector length (positive integer): ");
    if (scanf("%zu", &n) != 1 || n == 0) {
        fprintf(stderr, "Invalid length\n");
        return 1;
    }

    double *v1 = malloc(n * sizeof(double));
    double *v2 = malloc(n * sizeof(double));
    if (!v1 || !v2) {
        fprintf(stderr, "Memory allocation failed\n");
        free(v1); free(v2);
        return 1;
    }

    /* Read first vector */
    printf("Enter %zu elements of first vector separated by spaces or newlines:\n", n);
    for (size_t i = 0; i < n; ++i) {
        if (scanf("%lf", &v1[i]) != 1) {
            fprintf(stderr, "Invalid input\n");
            free(v1); free(v2);
            return 1;
        }
    }

    /* Read second vector */
    printf("Enter %zu elements of second vector separated by spaces or newlines:\n", n);
    for (size_t i = 0; i < n; ++i) {
        if (scanf("%lf", &v2[i]) != 1) {
            fprintf(stderr, "Invalid input\n");
            free(v1); free(v2);
            return 1;
        }
    }

    double result = dot_product(v1, v2, n);
    printf("Dot (scalar) product: %.10g\n", result);

    free(v1);
    free(v2);
    return 0;
}