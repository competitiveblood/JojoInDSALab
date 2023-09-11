#include <stdio.h>

int main() {
    int rows = 3;
    int cols = 3;

    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 9, 8}
    };

    printf("Original Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
           printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }

    int tempRow[rows];
    for (int i = 0; i < rows; i++) {
        tempRow[i] = matrix[i][0];
        matrix[i][0] = matrix[i][2];
        matrix[i][2] = tempRow[i];
    }

    printf("\nMatrix after swapping the first and third rows:\n");
    for (int i = 0; i < rows; i++) {
       for (int j = 0; j < cols; j++) {
           printf("%2d ", matrix[i][j]);
       }
       printf("\n");
    }
}