#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], f[n][n];

    for (i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
    }

    for (i = 0; i < n; i++) {
        printf("f[%d]: ", i);
        scanf("%f", &f[i][0]);
    }

    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            f[i][j] = f[i + 1][j - 1] - f[i][j - 1];
        }
    }

    printf("\nDifference Table:\n");
    for ( i = 0; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            printf("%f\t", f[i][j]);
        }
        printf("\n");
    }

    float value;
    printf("\nEnter the value to interpolate: ");
    scanf("%f", &value);

    float s = (value - x[0]) / (x[1] - x[0]);

    float y = f[0][0];
    float term = s;
    int fact = 1;

    for (i = 1; i < n; i++) {
        y += (term * f[0][i]) / fact;
        fact *= (i + 1);
        term *= (s - i);
    }

    printf("Interpolated value at %.2f: %.6f\n", value, y);

    return 0;
}
