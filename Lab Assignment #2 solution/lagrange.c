#include<stdio.h>
#include<math.h>

float f(float num) {
    return exp(num);
}
int main() {
    int order, n;
    float fix = 1.7;
    printf("Enter the no. of data: ");
    scanf("%d", &n);
    printf("Enter the order: ");
    scanf("%d", &order);
    
    int i, j;
    float x[n];
    printf("Enter the data point: ");
    for(i = 0; i < n; i ++) {
        scanf("%f", &x[i]);
    }
    float fnc[n];
    for(i = 0; i < n; i ++) {
        fnc[i] = f(x[i]);
    }
    float l[order];
    for(i = 0; i <= order; i ++) {
        l[i] = 1;
        for(j = 0; j <= order; j++) {
            if(i != j) {
                l[i] *= (fix - x[j]) / (x[i] - x[j]);
            }
        }
    }

    float value = 0.0;
    for(i = 0; i <= order; i ++) {
        value = value + (l[i] * fnc[i]);
    }

    printf("Interpolated value of %.2f: %.2f", fix, value);

    return 0;
}