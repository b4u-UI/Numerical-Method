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
    b[n] = 0;//initial condition in synthetic division
    printf("Quotient: ");
    while (n != 0)
    {
        b[n-1] = a[n] + (b[n] * divisor);
        printf("%d ", b[n-1]);
        n--;
    }
    int remainder;
    remainder = b[0];
    printf("\nRemainder: %d", b[0]);


    return 0;
}