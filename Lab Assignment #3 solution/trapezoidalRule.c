#include<stdio.h>
#include<math.h>
#define f(x) pow(x, 3) + 2
int main() {
	int x0, x1;
	printf("Enter the lower limit: ");
	scanf("%d", &x0);
	printf("Enter the upper limit: ");
	scanf("%d", &x1);
	float f0, f1;
	f0 = f(x0);
	f1 = f(x1);
	
	float integration = (float)(x1 - x0)/2 * (f0 + f1);
	printf("Integration using trapezoid at x0=%d and x1=%d is %.4f", x0, x1, integration);
	return 0;
}
