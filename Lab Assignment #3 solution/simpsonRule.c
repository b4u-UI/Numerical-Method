#include<stdio.h>
#include<math.h>
#define f(x) sqrt(1-x*x)
#define size 3

int main() {
	int lower, upper, i;
	printf("Enter the lower limt: ");
	scanf("%d", &lower);
	printf("Enter the upper limit: ");
	scanf("%d", &upper);
	
	float h = (float)(upper - lower) / 2.0;
	
	float x[size], y[size];
	for(i=0; i<size; i++) {
		x[i] = lower + i*h;
		y[i] = f(x[i]);
	}
	float result;
	result = y[0] + 4*y[1] + y[2];
	result = result * (h/3);
	
	printf("Using simpson rule, we get value = %.4f", result);
	
	return 0;
}
