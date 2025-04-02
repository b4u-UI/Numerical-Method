#include<stdio.h>
#define size 5
int main() {
	float x[size][size+1];
	int i, j;
	printf("Enter the value of x and f(x):\n");
	for(i=0; i<size; i++) {
		printf("x[%d]: ", i);
		scanf("%f", &x[i][0]);
		printf("Y[%d]: ", i);
		scanf("%f", &x[i][1]);
	}
	printf("\n");
	for(j=2; j<size+1; j++) {
		for(i=0; i<size-j+1; i++) {
			x[i][j] = x[i+1][j-1] - x[i][j-1];
		}
	}
	for(i=0; i<size; i++) {
		for(j=0; j<size+1-i; j++) {
			printf("%.4f  ", x[i][j]);
		}
		printf("\n");
	}
	float X;
	printf("\nEnter the value of x: ");
	scanf("%f", &X);
	float h = x[1][0] - x[0][0];
	float s = (X-x[size-1][0]) / h;
	
	float f_derivative;
	f_derivative = x[3][2] + (1.0/2.0) * (2*s+1)*x[2][3] + (1.0/6.0) * (3*s*s + 6*s + 2)*x[1][4] 
	+ (1.0/24.0) * (4*s*s*s + 18*s*s + 22*s + 6) * x[0][5];
	printf("Derivative at x = %.2f: %.6f",X, (f_derivative/h));
	return 0;
}
