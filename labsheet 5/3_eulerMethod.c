#include<stdio.h>
#define f(x, y) (2 * (x) + (y))
int main() {
	float x0, y0;
	printf("Enter the value of x0: ");
	scanf("%f", &x0);
	printf("Enter the value of y0: ");
	scanf("%f", &y0);
	
	float stepSize;
	int iteration;
	
	printf("Enter the step size(h): ");
	scanf("%f", &stepSize);
	
	printf("Enter the no. of itertion: ");
	scanf("%d", &iteration);
	
	int i;
	float x = x0;
	float y = y0;
	
	for(i=0; i<iteration; i++) {
		y = y + stepSize * f(x, y);
		x = x + stepSize;
		printf("Iteration %d\n", i+1);
		printf("y[%d]: %.4f\n\n", i+1, y);
	}
	return 0;
}
