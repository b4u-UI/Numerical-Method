#include<stdio.h>
#include<math.h>
#define f(x) pow(x, 3) + 1
#define size 4
int main() {
	int lower, upper;
	float x[size], y[size];
	printf("Enter the lower limit: ");
	scanf("%d", &lower);
	printf("Enter the upper limit: ");
	scanf("%d", &upper);
	float h = (upper - lower) / 3.0;
	int i;
	for(i=0; i<size; i++) {
		x[i] = lower + i * h;
		y[i] = f(x[i]); 
	}
	
	float result = y[0] + y[size-1];
	for(i=1; i<size-1; i++) {
		result += 3*y[i];
	}
	
	result = result * ((h*3.0)/8.0);
	printf("Using simpson 3/8 formula, we get : %.4f", result);
	return 0;
}
