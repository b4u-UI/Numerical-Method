#include <stdio.h>
#include <math.h>

#define MAX 10  // Maximum matrix size

void choleskyDecomposition(float A[MAX][MAX], float L[MAX][MAX], int n);

int main() {
    int n;
    float A[MAX][MAX], L[MAX][MAX] = {0};

    // Input matrix size
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    // Input matrix elements
    printf("Enter the elements of the symmetric, positive-definite matrix A (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &A[i][j]);
        }
    }

    // Perform Cholesky decomposition
    choleskyDecomposition(A, L, n);

    // Display the lower triangular matrix L
    printf("\nLower Triangular Matrix L:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.3f\t", L[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void choleskyDecomposition(float A[MAX][MAX], float L[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            float sum = 0;

            // Compute diagonal elements
            if (i == j) {
                for (int k = 0; k < j; k++)
                    sum += L[j][k] * L[j][k];

                L[j][j] = sqrt(A[j][j] - sum);
            } 
            // Compute non-diagonal elements
            else {
                for (int k = 0; k < j; k++)
                    sum += L[i][k] * L[j][k];

                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }
}

