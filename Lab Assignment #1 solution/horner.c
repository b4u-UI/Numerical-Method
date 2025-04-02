#include <stdio.h>
#define MAX 10
int main()
{
    int a[MAX];
    int n, i;

    printf("Enter degree of polynomial: ");
    scanf("%d", &n);
    for (i = 0; i <= n; i++)
    { 
        printf("Enter the coefficient %d(in ascending order): ", i + 1);
        scanf("%d", &a[i]);
    }

    int divisor;
    printf("Enter the divisor: ");
    scanf("%d", &divisor);

    int b[MAX];
    b[n] = a[n];//initial condition in horner Method
    printf("Quotient: ");
    while (n != 0)
    {
        b[n-1] = a[n-1] + (b[n] * divisor);
        printf("%d ", b[n-1]);
        n--;
    }
    int remainder;
    remainder = b[0];
    printf("\nRemainder and functionalValue(f(%d)): %d", divisor, b[0]);


    return 0;
}