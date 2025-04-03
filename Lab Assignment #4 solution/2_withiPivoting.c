#include <stdio.h>
#include <math.h>

#define MAX 10  // Maximum matrix size

// Function to perform row swapping (Pivoting)
void swapRows(float mat[MAX][MAX + 1], int row1, int row2, int n) {
	int i;
    for (i = 0; i <= n; i++) {
        float temp = mat[row1][i];
        mat[row1][i] = mat[row2][i];
        mat[row2][i] = temp;
    }
}

// Function for Gauss Elimination with Partial Pivoting
void gaussElimination(float mat[MAX][MAX + 1], int n) {
    int i, j, k;
    float factor, x[MAX];

    // Forward elimination process
    for (i = 0; i < n; i++) {
        // Pivoting: Find the row with the maximum element in column i
        int maxRow = i;
        for (j = i + 1; j < n; j++) {
            if (fabs(mat[j][i]) > fabs(mat[maxRow][i])) {
                maxRow = j;
            }
        }

        // Swap rows if needed
        if (maxRow != i) {
            swapRows(mat, i, maxRow, n);
        }

        // Make elements below pivot zero
        for (j = i + 1; j < n; j++) {
            factor = mat[j][i] / mat[i][i];
            for (k = i; k <= n; k++) {
                mat[j][k] -= factor * mat[i][k];
            }
        }
    }

    // Back substitution
    for (i = n - 1; i >= 0; i--) {
        x[i] = mat[i][n];
        for (j = i + 1; j < n; j++) {
            x[i] -= mat[i][j] * x[j];
        }
        x[i] /= mat[i][i];
    }

    // Display result
    printf("\nSolution:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %.3f\n", i, x[i]);
    }
}

int main() {
    int n, i, j;
    float mat[MAX][MAX + 1];

    // Input
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    printf("Enter the augmented matrix (coefficients and RHS values):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            scanf("%f", &mat[i][j]);
        }
    }

    // Perform Gauss Elimination with Pivoting
    gaussElimination(mat, n);

    return 0;
}

