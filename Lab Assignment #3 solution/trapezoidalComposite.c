#include<stdio.h>
#include<math.h>
#define f(x) exp(x)
int main() {
	int k, lower, higher, i;
	printf("Enter the value of K: ");
	scanf("%d", &k);
	printf("Enter the lower limit: ");
	scanf("%d", &lower);
	printf("Enter the upper limit: ");
	scanf("%d", &higher);
	
	float h = (float)(higher - lower) / k;
	float x[k+1], y[k+1];

	for(i=0; i<=k; i++) {
		x[i] = lower + i*h;
	}
	
	for(i=0; i<=k; i++) {
		y[i] = f(x[i]);
	}
	
	float result;
	result = y[0] + y[k];
	for(i=1; i<k; i++) {
		result = result + 2*y[i];
	}
	result = result * (h/2);
	
	printf("Using composite trapezoidal formula we get: %.4f", result);
	
	return 0;
}
