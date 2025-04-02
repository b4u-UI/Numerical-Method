#include<stdio.h>
#include<math.h>
#define f(x) ((x) * (x) - (x) - 2)
#define e 0.0001

int main() {
	float x0, x1, x2;
	printf("Enter the value of x0: ");
	scanf("%f", &x0);
	printf("Enter the value of x1: ");
	scanf("%f", &x1);
	
	float f0, f1, f2;
	int i = 1;
	
	f0 = f(x0);
	f1 = f(x1);
	
	if(f0 * f1 >= 0) {
		printf("Error!!");
		return 1;
	}

	do {
		x2 = x0 - ((f0 * (x1 - x0))/ (f1 - f0));
		f2 = f(x2);
		
		printf("\nIteration %d\n", i);
		printf("Root: %.4f\n", x2);
		
		if(f0 * f2 < 0) {
			x1 = x2;
			f1 = f2;
		} else {
			x0 = x2;
			f0 = f2;
		}
		i++;
	} while (fabs(f2) > e);
	
	printf("\nIteration completed!!\n");
	printf("The required root: %.4f", x2);
	return 0;
}
