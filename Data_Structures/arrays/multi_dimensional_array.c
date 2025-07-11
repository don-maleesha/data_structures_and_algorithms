#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void display2D(int rows, int cols, int arr[rows][cols]);
void display3D(int depth, int rows, int cols, int arr[depth][rows][cols]);
void input2D(int rows, int cols, int arr[rows][cols]);
void transpose2D(int rows, int cols, int arr[rows][cols], int result[cols][rows]);
int sum2D(int rows, int cols, int arr[rows][cols]);
void multiply2D(int r1, int c1, int arr1[r1][c1], int r2, int c2, int arr2[r2][c2], int result[r1][c2]);

int main() {
    int choice;
    
    printf("=== Multidimensional Array Operations ===\n");
    printf("1. 2D Array Operations\n");
    printf("2. 3D Array Operations\n");
    printf("3. Matrix Operations\n");
    printf("4. Dynamic 2D Array\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1: {
            // 2D Array Example
            printf("\n=== 2D Array Operations ===\n");
            int rows = 3, cols = 3;
            int arr2D[3][3] = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
            };
            
            printf("Original 2D Array:\n");
            display2D(rows, cols, arr2D);
            
            printf("\nSum of all elements: %d\n", sum2D(rows, cols, arr2D));
            
            // Transpose
            int transpose[3][3];
            transpose2D(rows, cols, arr2D, transpose);
            printf("\nTranspose of the matrix:\n");
            display2D(cols, rows, transpose);
            break;
        }
        
        case 2: {
            // 3D Array Example
            printf("\n=== 3D Array Operations ===\n");
            int depth = 2, rows = 2, cols = 3;
            int arr3D[2][2][3] = {
                {{1, 2, 3}, {4, 5, 6}},
                {{7, 8, 9}, {10, 11, 12}}
            };
            
            printf("3D Array:\n");
            display3D(depth, rows, cols, arr3D);
            break;
        }
        
        case 3: {
            // Matrix Operations
            printf("\n=== Matrix Multiplication ===\n");
            int matrix1[2][3] = {{1, 2, 3}, {4, 5, 6}};
            int matrix2[3][2] = {{7, 8}, {9, 10}, {11, 12}};
            int result[2][2];
            
            printf("Matrix 1 (2x3):\n");
            display2D(2, 3, matrix1);
            
            printf("Matrix 2 (3x2):\n");
            display2D(3, 2, matrix2);
            
            multiply2D(2, 3, matrix1, 3, 2, matrix2, result);
            printf("Result of Matrix1 × Matrix2 (2x2):\n");
            display2D(2, 2, result);
            break;
        }
        
        case 4: {
            // Dynamic 2D Array
            printf("\n=== Dynamic 2D Array ===\n");
            int rows, cols;
            printf("Enter number of rows: ");
            scanf("%d", &rows);
            printf("Enter number of columns: ");
            scanf("%d", &cols);
            
            // Allocate memory for 2D array
            int **dynamicArr = (int**)malloc(rows * sizeof(int*));
            for(int i = 0; i < rows; i++) {
                dynamicArr[i] = (int*)malloc(cols * sizeof(int));
            }
            
            printf("Enter elements for %dx%d array:\n", rows, cols);
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < cols; j++) {
                    printf("Element [%d][%d]: ", i, j);
                    scanf("%d", &dynamicArr[i][j]);
                }
            }
            
            printf("\nDynamic 2D Array:\n");
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < cols; j++) {
                    printf("%4d ", dynamicArr[i][j]);
                }
                printf("\n");
            }
            
            // Free allocated memory
            for(int i = 0; i < rows; i++) {
                free(dynamicArr[i]);
            }
            free(dynamicArr);
            break;
        }
        
        default:
            printf("Invalid choice!\n");
    }
    
    return 0;
}

// Function to display 2D array
void display2D(int rows, int cols, int arr[rows][cols]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Function to display 3D array
void display3D(int depth, int rows, int cols, int arr[depth][rows][cols]) {
    for(int k = 0; k < depth; k++) {
        printf("Layer %d:\n", k + 1);
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                printf("%4d ", arr[k][i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

// Function to input elements into 2D array
void input2D(int rows, int cols, int arr[rows][cols]) {
    printf("Enter elements for %dx%d array:\n", rows, cols);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

// Function to transpose a 2D array
void transpose2D(int rows, int cols, int arr[rows][cols], int result[cols][rows]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[j][i] = arr[i][j];
        }
    }
}

// Function to calculate sum of all elements in 2D array
int sum2D(int rows, int cols, int arr[rows][cols]) {
    int sum = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}

// Function to multiply two 2D matrices
void multiply2D(int r1, int c1, int arr1[r1][c1], int r2, int c2, int arr2[r2][c2], int result[r1][c2]) {
    if(c1 != r2) {
        printf("Matrix multiplication not possible!\n");
        return;
    }
    
    // Initialize result matrix with zeros
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            result[i][j] = 0;
        }
    }
    
    // Perform multiplication
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            for(int k = 0; k < c1; k++) {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}