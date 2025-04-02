#include <stdio.h>

// Function to calculate Newton's Divided Difference Interpolation
void newtonDividedDifference(float x[], float fx[], int n, float value) {
    float dd[n]; // Array for divided differences
    int i, j;
    
    // Step 1: Copy fx[i] to dd[i]
    for (i = 0; i < n; i++) {
        dd[i] = fx[i];
    }

    // Step 2: Compute divided differences
    for (i = 0; i < n - 1; i++) {
        for (j = n - 1; j > i; j--) {
            dd[j] = (dd[j] - dd[j - 1]) / (x[j] - x[j - 1 - i]);
        }
    }

    // Step 3: Initialize variables for interpolation
    float v = 0, p = 1;

    // Step 4: Compute interpolated value
    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            p *= (value - x[j]);  // Compute product (x - x_j)
        }
        v += dd[i] * p;  // Compute interpolated value
        p = 1;  // Reset p for next iteration
    }

    // Output the interpolated value
    printf("Interpolated value at x = %.2f is: %.5f\n", value, v);
}

int main() {
    int n;
    float value;

    // Read the number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], fx[n];

    // Read data points
    printf("Enter the x and f(x) values:\n");
    int i;
    for ( i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("f(x[%d]): ", i);
        scanf("%f", &fx[i]);
    }

    // Read the value to be interpolated
    printf("Enter the value at which interpolation is needed: ");
    scanf("%f", &value);

    // Perform interpolation
    newtonDividedDifference(x, fx, n, value);

    return 0;
}

