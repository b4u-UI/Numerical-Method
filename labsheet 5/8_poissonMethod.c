#include<stdio.h>
#include<math.h>

#define MAX 100  // Maximum grid size
#define MAX_ITER 10000  // Maximum number of iterations for convergence

// Function to initialize the grid with boundary conditions
void initializeGrid(double grid[MAX][MAX], int N, double boundary_value) {
	int i, j;
    for ( i = 0; i < N; i++) {
        for ( j = 0; j < N; j++) {
            if (i == 0 || j == 0 || i == N - 1 || j == N - 1) {
                grid[i][j] = boundary_value;  // Set boundary conditions
            } else {
                grid[i][j] = 0.0;  // Initialize inner grid points
            }
        }
    }
}

// Function for the Poisson equation source term f(x, y)
double sourceTerm(double x, double y) {
    // Example: f(x, y) = 2 * (x^2 + y^2) as an example source term
    return 2 * (x*x + y*y);
}

// Function to solve the Poisson equation using the finite difference method
void solvePoisson(double grid[MAX][MAX], int N, double h, double tolerance) {
    double temp[MAX][MAX];
    int iter = 0;
    double error = 1.0;
    
    // Declare loop variables outside the loop
    int i, j;
    
    while (iter < MAX_ITER && error > tolerance) {
        error = 0.0;
        
        // Copy the current grid to temp for update
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                temp[i][j] = grid[i][j];
            }
        }
        
        // Iterate over the grid and update the values
        for (i = 1; i < N-1; i++) {
            for (j = 1; j < N-1; j++) {
                double x = i * h;
                double y = j * h;
                
                // Apply the finite difference scheme
                grid[i][j] = 0.25 * (temp[i+1][j] + temp[i-1][j] + temp[i][j+1] + temp[i][j-1] + h*h * sourceTerm(x, y));
                
                // Calculate the error as the maximum difference between old and new values
                error = fmax(error, fabs(grid[i][j] - temp[i][j]));
            }
        }
        
        iter++;
    }
    
    if (iter == MAX_ITER) {
        printf("Solution did not converge within the maximum number of iterations\n");
    } else {
        printf("Solution converged in %d iterations\n", iter);
    }
}

// Function to print the  solution grid
void printGrid(double grid[MAX][MAX], int N) {
	int i, j;
    for ( i = 0; i < N; i++) {
        for ( j = 0; j < N; j++) {
            printf("%f ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int N;
    double h, boundary_value, tolerance;
    
    // Input the grid size (number of points in each direction)
    printf("Enter the grid size (N x N): ");
    scanf("%d", &N);
    
    // Grid spacing (h = 1 / (N-1))
    h = 1.0 / (N - 1);
    
    // Input boundary conditions and tolerance
    printf("Enter the boundary condition value: ");
    scanf("%lf", &boundary_value);
    
    printf("Enter the tolerance for convergence: ");
    scanf("%lf", &tolerance);
    
    // Initialize the grid
    double grid[MAX][MAX];
    initializeGrid(grid, N, boundary_value);
    
    // Solve the Poisson equation
    solvePoisson(grid, N, h, tolerance);
    
    // Print the solution
    printf("Solution to the Poisson equation:\n");
    printGrid(grid, N);
    
    return 0;
}

