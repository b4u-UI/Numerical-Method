#include <stdio.h>
#include<math.h>
#define MAX 10

void upperTriangle(float a[][2 * MAX], int n);
void lowerTriangle(float a[][2 * MAX], int n);

int main() {
    int n, i, j;
    printf("Enter the size of matrix: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("Matrix size exceeds maximum allowed size (%d).\n", MAX);
        return 1;
    }

    float a[MAX][2 * MAX]; 

  
    printf("Enter the coefficients of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("a[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = n; j < 2 * n; j++) {
            if (j == i + n) {
                a[i][j] = 1.0; 
            } else {
                a[i][j] = 0.0; 
            }
        }
    }

    upperTriangle(a, n);
    lowerTriangle(a, n);

    for(i=0; i<n; i++) {
		float constant = a[i][i];
		for(j=0; j<2*n; j++) {
			a[i][j] = a[i][j] / constant;
		}
	}

    printf("\nInverse of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = n; j < 2 * n; j++) {
            printf("%.3f  ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void upperTriangle(float arr[][2 * MAX], int size) {
    int i, j, k;
    float ratio;
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            ratio = arr[j][i] / arr[i][i];
            for (k = 0; k < 2 * size; k++) {
                arr[j][k] = arr[j][k] - (ratio * arr[i][k]);
            }
        }
    }
}

void lowerTriangle(float arr[][2 * MAX], int size) {
    int i, j, k;
    float ratio;

    for (i = size - 1; i >= 0; i--) {
        for (j = i - 1; j >= 0; j--) {
            ratio = arr[j][i] / arr[i][i];
            for (k = 0; k < 2 * size; k++) {
                arr[j][k] = arr[j][k] - (ratio * arr[i][k]);
            }
        }
    }
}
