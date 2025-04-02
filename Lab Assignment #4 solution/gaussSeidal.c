#include<stdio.h>
#include<math.h>

#define f1(x, y, z) (11 + 2*y - z) / 6
#define f2(x, y, z) (5 + 2*x - 2*z) / 7
#define f3(x, y, z) (x + 2*y + 1) / 5
#define e 0.0001

int main() {
	float x, y, z;
	float x0, x1, x2;
	float e1, e2, e3;
	int i =0;
	
	x = y = z = 0.0;
	
	do {
		x0 = f1(x, y, z);
		e1 = fabs(x - x0);
		x = x0;
		
		x1 = f2(x, y, z);
		e2 = fabs(y - x1);
		y = x1;
		
		x2 = f3(x, y, z);
		e3 = fabs(z - x2);
		z = x2;
		
		printf("Iteration %d\n", i+1);
		printf("x1 = %.4f\nx2 = %.4f\nx3 = %.4f\n\n", x0, x1, x2);
		i++;
	} while (e1 > e && e2 > e && e3> e);
	printf("ITERATION FINISHED!!!\nTherefore, required roots are: \n");
	printf("x1 = %.4f, x2 = %.4f, x3 = %.4f", x0, x1, x2);
	
	return 0;
}
