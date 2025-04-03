#include<stdio.h>
#include<math.h>
#define f(x, y) x - y*y
#define ff(x, y) 1 - 2*y*(f(x, y))
#define fff(x, y) (-2 * (ff(x, y) * y + f(x, y) * f(x, y)))

int main() {
	float x0, y;
	printf("Enter the value of x0: ");
	scanf("%f", &x0);
	printf("Enter the value of y: ");
	scanf("%f", &y);
	
	float first_d, second_d, third_d;
	first_d = f(x0, y);
	second_d = ff(x0, y);
	third_d = fff(x0, y);
	
	float x;
	printf("Enter the value of x: ");
	scanf("%f", &x);
	
	float result;
	result = y + (x - x0)*first_d + (pow(x-x0, 2) * second_d) / 2 + (pow(x-x0, 3) * third_d) / 6 ;
	
	printf("The approximate value of y(x) is: %.4f\n", result);
	return 0;
}
