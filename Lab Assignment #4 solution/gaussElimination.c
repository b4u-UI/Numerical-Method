#include <stdio.h>

void upperTriangle(float arr[][10], int size) {
    int i, j, k;
    float ratio;
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            ratio = arr[j][i] / arr[i][i];
            for (k = 0; k <= size; k++) {
                arr[j][k] = arr[j][k] - (ratio * arr[i][k]);
            }
        }
    }
}

void backSubstitution(float arr[][10], int size, float solution[]) {
    int i, j;
    for (i = size - 1; i >= 0; i--) {
        solution[i] = arr[i][size];
        for (j = i + 1; j < size; j++) {
            solution[i] = solution[i] - arr[i][j] * solution[j];
        }
        solution[i] = solution[i] / arr[i][i];
    }
}

int main() {
    int n, i, j;
    printf("Enter the size of matrix: ");
    scanf("%d", &n);

    float a[n][10];
    printf("Enter the coefficient in matrix form:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    float value[n];
    printf("Enter the constants:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &value[i]);
    }

    for (i = 0; i < n; i++) {
        a[i][n] = value[i];
    }

    printf("Augmented Form:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            printf("%.3f  ", a[i][j]);
        }
        printf("\n");
    }

    upperTriangle(a, n);

    printf("Upper Triangular Form:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            printf("%.3f  ", a[i][j]);
        }
        printf("\n");
    }

    float solution[n];
    backSubstitution(a, n, solution);

    printf("Solution:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %.3f\n", i + 1, solution[i]);
    }

    return 0;
}
