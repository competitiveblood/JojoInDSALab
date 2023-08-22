#include <stdio.h>

int main() {
    int size = 3; // Size of the square matrix

    int square_matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int three_d_matrix[3][3][1]; // Define a 3D matrix

    // Copy data from the square matrix into the 3D matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            three_d_matrix[i][j][0] = square_matrix[i][j];
        }
    }

    // Print the resulting 3D matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", three_d_matrix[i][j][0]);
        }
        printf("\n");
    }

    return 0;
}

