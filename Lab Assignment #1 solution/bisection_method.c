#include<stdio.h>
#include<math.h>
#define f(x) (x*x-4*x-10)
#define e 0.001
int  main() {
    float x0, x1,x2;
    float f0, f1, f2;
    float absolute;
    int i=1;
        printf("Enter the value of X1 and X2: ");
        scanf("%f %f",&x1, &x2);
        f1=f(x1);
        f2=f(x2);
        if(f1 * f2 > 0) {
            printf("Incorrect initial guess.");
            return 1;
        }
        do {
                x0 = (x1 + x2) / 2.0;
                f0 = f(x0);
                if(f0 * f1 < 0) {
                    x2 = x0;
                    f2 = f0;
                }
                else {
                    x1 = x0;
                    f1 = f0;
                }
                absolute = fabs((x2 - x1) / x2);
                printf("%d iteration", i);
                printf("\nRoot: %f" , x0);
                printf("\nError: %f", absolute);
                printf("\n\n");
                i++;
        }
        while (absolute > e);
        printf("The root is approximately: %f\n", x0);
    return 0;
}