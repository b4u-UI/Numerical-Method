#include<stdio.h>

int main() {
	int size;
	printf("Enter the size of x: ");
	scanf("%d", &size);
	int x[size], y[size], xx[size], xy[size];
	int i;
	printf("Enter X and f(x) of %d data:\n", size);
	for(i=0; i<size; i++) {
		printf("x[%d]: ",i);
		scanf("%d", &x[i]);
		printf("y[%d]: ",i);
		scanf("%d", &y[i]);
		printf("\n");
	}
	for(i=0; i<size; i++) {
		xx[i] = x[i] * x[i];
		xy[i] = x[i] * y[i];
	}
	int sum_x = 0;
	int sum_y = 0;
	int sum_xx = 0;
	int sum_xy = 0;
	
	for(i=0; i<size; i++) {
		sum_x = sum_x + x[i];
		sum_y = sum_y + y[i];
		sum_xx = sum_xx + xx[i];
		sum_xy = sum_xy + xy[i];
	}
	
	float a, b;
	b = (float)(size * sum_xy - sum_x* sum_y) / (size * sum_xx - (sum_x)*(sum_x));
	a = (float) sum_y / size - b * (float)(sum_x / size);
	printf("The required linear least square equation:\n Y = %.3f + %.3fX", a, b);
	return 0;
}
