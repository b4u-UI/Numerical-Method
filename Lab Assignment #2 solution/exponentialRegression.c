#include <stdio.h>
#include <math.h>

int main() {
    int n, i;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];
    double sum_x = 0, sum_y = 0, sum_x2 = 0, sum_xy = 0;

    // Input data points
    for (i = 0; i < n; i++) {
        printf("Enter x[%d]: ", i);
        scanf("%lf", &x[i]);
        printf("Enter y[%d]: ", i);
        scanf("%lf", &y[i]);
    }

    // Calculate summations for x, ln(y), x², and x * ln(y)
    for (i = 0; i < n; i++) {
        double ln_y = log(y[i]);
        sum_x += x[i];
        sum_y += ln_y;         // sum of ln(y)
        sum_x2 += x[i] * x[i]; // sum of x²
        sum_xy += x[i] * ln_y; // sum of x * ln(y)
    }

    // Calculate b and A (ln(a))
    double b = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    double A = (sum_y - b * sum_x) / n;
    double a = exp(A); // a = e^A

    // Output the exponential regression equation: y = a * e^(b * x)
    printf("\nThe exponential regression equation: y = %.6lf * e^(%.6lf * x)\n", a, b);

    return 0;
}

