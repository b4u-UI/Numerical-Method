#include<stdio.h>
#include<math.h>
#define f(x) sqrt(1-x*x)
int main() {
	int k, i;
	printf("Enter the value of K: ");
	scanf("%d", &k);
	if(k%2 != 0) {
		printf("K cannot be odd!!, try again");
		return 1;
	}
	int lower, upper;
	printf("Enter the lower limit: ");
	scanf("%d", &lower);
	printf("Enter the higher limit: ");
	scanf("%d", &upper);
	
	float h = (float) (upper - lower) / k;
	float x[k+1], y[k+1];
	for(i=0; i<=k; i++) {
		x[i] = lower + i * h;
		y[i] = f(x[i]);
	}
	float result = y[0] + y[k];
	for(i=1; i<k; i++) {
		if(i % 2 != 0) {
			result = result + 4 * y[i];
		} else {
			result = result + 2 * y[i];
		}
	}
	result = result * (h/3.0);
	printf("Using composite simpson 1/3 we get, Integration = %.4f", result);
	return 0;
}
