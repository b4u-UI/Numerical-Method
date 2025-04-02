#include<stdio.h>
#include<math.h>
#define fnc(x, a, b) (2*a*x) + b

void minMaxCalc(float f[][4], float);

int main() {
	float x[4], f[4][4];
	printf("Enter the data points:\n");
	int i, j;
	for(i=0; i<4; i++) {
		printf("x[%d]: ", i);
		scanf("%f", &x[i]);
	}
	int h = x[1] - x[0];
	printf("Enter the value of f(x):\n");
	for(i=0; i<4; i++) {
		printf("f[%d]: ", i);
		scanf("%f", &f[i][0]);
	}
	for (j = 1; j < 4; j++) {
        for (i = 0; i < 4 - j; i++) {
            f[i][j] = f[i + 1][j - 1] - f[i][j - 1];
        }
    }
    
    printf("Newton Forward Table:\n");
    for(i=0; i<4; i++) {
    	for(j=0; j<4-i; j++) {
    		printf("%.2f\t", f[i][j]);
		}
		printf("\n");
	}

	float a, b, c;
	a = (f[0][3])/2.0;
	b = f[0][2] - f[0][3];
	c = f[0][1] - ((f[0][2])/2.0) + ((f[0][3]) / 3.0);

	if(a == 0) {
		printf("No real root found!!");
		return 1;
	}
	float determinant = sqrt(b*b - (4*a*c));
	float root1 =  (- b + determinant) / (2*a);
	float root2 =  (- b - determinant) / (2*a);

	printf("\nRoot1: %.4f\t", root1);
	printf("Root2: %.4f\n\n", root2);

	float x1, x2;
	x1 = root1 * h + x[0];
	x2 = root2 * h + x[0];

	float second_d1 = fnc(x1, a, b);
	float second_d2 = fnc(x2, a, b);

	if(second_d1 > 0) {
		printf("Local Minima at point x = %.4f\n", root1);
		minMaxCalc(f, root1);
	} else{
		printf("Local Maxima at point x = %.4f\n", root1);
		minMaxCalc(f, root1);
	}
	if(second_d2 > 0) {
		printf("Local Minima at point x = %.4f\n", root2);
		minMaxCalc(f, root2);
	} else {
		printf("Local Maxima at point x = %.4f\n", root2);
		minMaxCalc(f, root2);
	}
	return 0;
}

void minMaxCalc(float f[][4], float s) {
	float result;
	result = f[0][0] + (s * f[0][1]) + 
		((s * (s - 1) * f[0][2])/ 2) + 
		((s * (s -1) * (s -2 ) * f[0][3]) / 6);
	printf("Required value: %.4f\n\n", result);
}
