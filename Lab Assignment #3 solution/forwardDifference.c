#include<stdio.h>
#include<math.h>
#define f(x) pow(x, 2)
int main() {
	float x, h;
	printf("Enter the value of X: ");
	scanf("%f", &x);
	printf("Enter the value of h: ");
	scanf("%f", &h);
	
	float f1 = f(x+h);
	float f2 = f(x);

	float f_derivative = (float)(f1-f2) / h;
	printf("Derivative of f(x) at x = %.2f and h = %.2f is %.3f", x, h, f_derivative);
	return 0;
}
