#include<stdio.h>
#include<math.h>

// Function prototypes
float f1(float x, float y, float yp);
float f2(float x, float y, float yp);

void rk4(float (*f1)(float, float, float), float (*f2)(float, float, float), float y0, float yp0, float x0, float x1, float h, int n);

int main() {
    float x0 = 0.0, y0 = 1.0, yp0 = 1.0;   // Initial condition: y(0) = 1, y'(0) = 1 (initial guess for shooting)
    float x1 = 1.0, y1 = 0.0;               // Boundary condition: y(1) = 0
    float h = 0.1;                          // Step size
    int n = (x1 - x0) / h;                  // Number of steps
    
    // Now we apply the shooting method. Let's start by solving with an initial guess for y'(0).
    printf("Initial guess for y'(0) = %.4f\n", yp0);
    
    rk4(f1, f2, y0, yp0, x0, x1, h, n);
    
    return 0;
}

// Function definitions
float f1(float x, float y, float yp) {
    return yp;  // f1 is y'
}

float f2(float x, float y, float yp) {
    return -2 * yp - 3 * y;  // f2 is y'' (for this example)
}

void rk4(float (*f1)(float, float, float), float (*f2)(float, float, float), float y0, float yp0, float x0, float x1, float h, int n) {
    float x = x0, y = y0, yp = yp0;
    float k1, k2, k3, k4, l1, l2, l3, l4;
    
    printf("Shooting method results (RK4):\n");
    
    // Declare and initialize variables outside the loop
    int i;
    
    for (i = 0; i <= n; i++) {
        // Print values of x, y, and y' at each step
        printf("x = %.4f, y = %.4f, y' = %.4f\n", x, y, yp);
        
        // Calculate slopes using RK4
        k1 = h * f1(x, y, yp);
        l1 = h * f2(x, y, yp);
        
        k2 = h * f1(x + h / 2, y + k1 / 2, yp + l1 / 2);
        l2 = h * f2(x + h / 2, y + k1 / 2, yp + l1 / 2);
        
        k3 = h * f1(x + h / 2, y + k2 / 2, yp + l2 / 2);
        l3 = h * f2(x + h / 2, y + k2 / 2, yp + l2 / 2);
        
        k4 = h * f1(x + h, y + k3, yp + l3);
        l4 = h * f2(x + h, y + k3, yp + l3);
        
        // Update y and y'
        y += (k1 + 2*k2 + 2*k3 + k4) / 6;
        yp += (l1 + 2*l2 + 2*l3 + l4) / 6;
        
        // Increment x
        x += h;
    }
    
    printf("Final values: y(%.4f) = %.4f\n", x1, y);
}

