#include <stdio.h>

#define MAX 10  // Maximum size of the matrix

void doolittleLU(float A[MAX][MAX], float L[MAX][MAX], float U[MAX][MAX], int n);

int main() {
    int n, i, j;
    float A[MAX][MAX], L[MAX][MAX] = {0}, U[MAX][MAX] = {0};
    
    // Input the matrix size
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    // Input the matrix elements
    printf("Enter the elements of the matrix A (%d x %d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%f", &A[i][j]);
        }
    }

    // Perform LU decomposition
    doolittleLU(A, L, U, n);

    // Display the L matrix
    printf("\nLower Triangular Matrix L:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.3f\t", L[i][j]);
        }
        printf("\n");
    }

    // Display the U matrix
    printf("\nUpper Triangular Matrix U:\n");
    for (i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            printf("%.3f\t", U[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void doolittleLU(float A[MAX][MAX], float L[MAX][MAX], float U[MAX][MAX], int n) {
    int i, j, k;
	for (i = 0; i < n; i++) {
        // Compute upper triangular matrix U
        for (j = i; j < n; j++) {
            float sum = 0;
            for (k = 0; k < i; k++)
                sum += L[i][k] * U[k][j];
            U[i][j] = A[i][j] - sum;
        }

        // Compute lower triangular matrix L
        for (j = i; j < n; j++) {
            if (i == j)
                L[i][i] = 1;  // Diagonal elements of L are 1
            else {
                float sum = 0;
                for (k = 0; k < i; k++)
                    sum += L[j][k] * U[k][i];
                L[j][i] = (A[j][i] - sum) / U[i][i];
            }
        }
    }
}

