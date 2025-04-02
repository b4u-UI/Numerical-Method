#include<stdio.h>
#include<math.h>
#define f(x) sqrt(1-x*x)

int main() {
	int lower, upper, k, i;
	
	printf("Enter the value of k: ");
	scanf("%d", &k);
	
	printf("Enter the lower limit: ");
	scanf("%d", &lower);
	printf("Enter the upper limit: ");
	scanf("%d", &upper);
	
	float h = (upper - lower) / k;
	
	float x[k+1], y[k+1];
	for(i=0; i<=k; i++) {
		x[i] = lower + i * h;
		y[i] = f(x[i]); 
	}
	
	float result = y[0] + y[k];
	for(i=1; i<k; i++) {
		if(i % 3 == 0) {
			result = result + 2 * y[i];
		} else {
			result += 3 * y[i];
		}
	}
	
	result = result * ((h*3.0)/8.0);
	printf("Using simpson 3/8 formula, we get : %.4f", result);
	return 0;
}
