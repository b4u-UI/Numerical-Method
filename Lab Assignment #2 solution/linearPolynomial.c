#include <stdio.h>

#define MAX 50

int main() {
    int n, i;
    float x[MAX], y[MAX];
    
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the x and y values:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("y[%d]: ", i);
        scanf("%f", &y[i]);
    }


    float sum_x = 0, sum_y = 0, sum_x2 = 0, sum_x3 = 0, sum_x4 = 0;
    float sum_xy = 0, sum_x2y = 0;

    for (i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_x2 += x[i] * x[i];
        sum_x3 += x[i] * x[i] * x[i];
        sum_x4 += x[i] * x[i] * x[i] * x[i];
        sum_xy += x[i] * y[i];
        sum_x2y += x[i] * x[i] * y[i];
    }

    float D = (n * (sum_x2 * sum_x4 - sum_x3 * sum_x3)) - (sum_x * (sum_x * sum_x4 - sum_x3 * sum_x2)) + (sum_x2 * (sum_x * sum_x3 - sum_x2 * sum_x2));

    float D1 = (sum_y * (sum_x2 * sum_x4 - sum_x3 * sum_x3)) - (sum_x * (sum_xy * sum_x4 - sum_x3 * sum_x2y)) + (sum_x2 * (sum_xy * sum_x3 - sum_x2 * sum_x2y));

    float D2 = (n * (sum_xy * sum_x4 - sum_x3 * sum_x2y)) - (sum_y * (sum_x * sum_x4 - sum_x3 * sum_x2)) + (sum_x2 * (sum_x * sum_x2y - sum_xy * sum_x2));

    float D3 = (n * (sum_x2 * sum_x2y - sum_xy * sum_x3)) - (sum_x * (sum_x * sum_x2y - sum_xy * sum_x2)) + (sum_y * (sum_x * sum_x3 - sum_x2 * sum_x2));

    float a0 = D1 / D;
    float a1 = D2 / D;
    float a2 = D3 / D;

    printf("\nThe polynomial regression equation is:\n");
    printf("y = %.4f + %.4f * x + %.4f * x^2\n", a0, a1, a2);

    return 0;
}

