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
	float m1, m2, m3, m4;
	for(i=0; i<iteration; i++) {
		m1 = f(x, y);
		m2 = f(x + (stepSize/2), y + ((stepSize/2) * m1));
		m3 = f(x + (stepSize/2), y + ((stepSize/2) * m2));
		m4 = f(x + stepSize, y + (stepSize * m3));
		
		y = y + ((stepSize)/ 6) * (m1 + 2 * m2 + 2 * m3 + m4);
		x = x + stepSize;
		printf("Iteration %d\n", i+1);
		printf("y[%d]: %.4f\n\n", i+1, y);
	}
	return 0;
}
