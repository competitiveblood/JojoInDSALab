#include <stdio.h>

int main() {
    int rows = 3;
    int cols = 3;
    
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Original Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }

    int tempRow[cols];
    for (int j = 0; j < cols; j++) {
        tempRow[j] = matrix[0][j];
        matrix[0][j] = matrix[2][j];
        matrix[2][j] = tempRow[j];
    }

    // Display the matrix after swapping
    printf("\nMatrix after swapping the first and third rows:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
