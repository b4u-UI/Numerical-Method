#include<stdio.h>
#define f(x, y) (2*x) + y
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
	float m1, m2;
	for(i=0; i<iteration; i++) {
		m1 = f(x, y);
		x = x + stepSize;
		m2 = f(x, y + (stepSize*m1));
		
		y = y + ((stepSize)/ 2) * (m1 + m2);
		printf("Iteration %d\n", i+1);
		printf("y[%d]: %.4f\n\n", i+1, y);
	}
	return 0;
}
