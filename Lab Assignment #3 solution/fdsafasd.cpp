#include<stdio.h>
#include<math.h>

int main() {
	int k, i;

	printf("Enter the value of k: ");
	scanf("%d", &k);
		float x[k+1], y[k+1];


	for(i=0; i<= k; i++) {
		printf("Enter x[%d]: ", i);
		scanf("%f", &x[i]);
		printf("Enter y[%d]: ", i);
		scanf("%f", &y[i]);
	}
	float h = (x[k] - x[0]) / k;
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
