#include<stdio.h>
#define MAX 10

void upperTriangle(float a[][10], int n);
void lowerTriangle(float a[][10], int n);

int main() {
	int n, i, j;
    printf("Enter the size of matrix: ");
    scanf("%d", &n);

    float a[n][10];
    printf("Enter the coefficient in matrix form:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    float value[n];
    printf("Enter the constants:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &value[i]);
    }

    for (i = 0; i < n; i++) {
        a[i][n] = value[i];
    }
	 upperTriangle(a, n);
	 lowerTriangle(a, n);
	 
	for(i=0; i<n; i++) {
		float constant = a[i][i];
		for(j=0; j<n+1; j++) {
			a[i][j] = a[i][j] / constant;
		}
	}
    printf("Reduced row echelon form:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            printf("%.3f  ", a[i][j]);
        }
        printf("\n");
    }
    printf("\nRequired roots are: ");
    for(i=0; i<n; i++) {
    	printf("%.3f ", a[i][n]);
	}
    
	return 0;
}
void upperTriangle(float arr[][10], int size) {
    int i, j, k;
    float ratio;
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            ratio = arr[j][i] / arr[i][i];
            for (k = 0; k <= size; k++) {
                arr[j][k] = arr[j][k] - (ratio * arr[i][k]);
            }
        }
    }
}
void lowerTriangle(float arr[][10], int size) {
    int i, j, k;
    float ratio;

    for (i = size - 1; i >= 0; i--) {
        for (j = i - 1; j >= 0; j--) {
            ratio = arr[j][i] / arr[i][i];
            for (k = 0; k <= size; k++) {
                arr[j][k] = arr[j][k] - (ratio * arr[i][k]);
            }
        }
    }
}
