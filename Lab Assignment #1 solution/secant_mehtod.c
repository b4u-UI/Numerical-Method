#include<stdio.h>
#include<math.h>
#define f(x) (x*x -4*x-10)
#define e 0.001

int main() {
    float x0, x1, x2;
    float f0, f1, f2;
    float absolute, numerator, denominator;
    int i=1;
    printf("Enter the initial value x1 and x2: ");
    scanf("%f %f", &x1, &x2);
    f1 = f(x1);
    f2 = f(x2);
    if(f1 == f2) {
        printf("Initial guess cannot be equal");
        return 1;
    }
    do {
        numerator = f2 * (x2-x1);
        denominator = f2 - f1;
        x0 = x2 - (numerator)/ (denominator);
        f0 = f(x0);
        absolute = fabs((x0 - x2) / x0);
        x1 = x2;
        x2 = x0;
        f1 = f2;
        f2 = f0;
        printf("Iteration: %d", i);
        printf("\nError: %f", absolute);
        printf("\nRoot: %f\n\n", x0);
        i++;
    }
    while (absolute > e);
    printf("The approximate root: %f", x0);
    return 0;
}