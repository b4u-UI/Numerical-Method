#include<stdio.h>
#include<math.h>
#define f(x) (x*x - 3*x + 2)
#define ff(x)(x-3)
#define e 0.00000001

int main() {
    float x1, x0;
    printf("Enter initial value of x0: ");
    scanf("%f", &x0);
    float f0, f1;
    float ff0, ff1;
    f0 = f(x0);
    ff0 = ff(x0);

    int i = 1;
    float absolute;
    do {
        x1 = x0 - (f0/ ff0);
        absolute = fabs((x1 - x0) / x1);
        x0 = x1;
        f0 = f(x1);
        ff0 = ff(x1);
        printf("Iteration: %d", i);
        printf("\nError: %f", absolute);
        printf("\nRoot: %f\n\n", x1);
        i++;
    } while (absolute > e);
    printf("The approximate root: %f", x1);
return 0;
}