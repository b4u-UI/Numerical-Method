 #include<stdio.h>
#include<math.h>
#define f(x)((cos(x)+1) / 3 )
#define e 0.001

int main() {
    float x0, x1;
    printf("Enter the initial number: ");
    scanf("%f", &x0);
    float f1;
    float absolute;
    int i=1;
    do {
        f1 = f(x0);
        x1 = f1;
        absolute = fabs((x1 - x0)/ x1);
        x0 = x1;
        printf("%d iteration", i);
        printf("\nRoot: %f" , x1);
        printf("\nError: %f", absolute);
        printf("\n\n");
        i++;
    } while(absolute > e);
    
    printf("The approximate root: %f", x1);
    return 0;
}