#include<stdio.h>
#include<math.h>

#define f(x, y) x*x + y*y
#define ff(x) pow(x, 3) / 3
#define fff(x) (pow(x, 3)/ 3) + (pow(x, 7) / 63)

int main() {
	float x;
	printf("Enter the value of x: ");
	scanf("%f", &x);
	
	float first_d, second_d;
	first_d = ff(x);
	second_d = fff(x);
	
	printf("The approximate root of ODE at x = %.3f:\ny'=%.4f and y''=%.4f", x, first_d, second_d);
	return 0;
}
