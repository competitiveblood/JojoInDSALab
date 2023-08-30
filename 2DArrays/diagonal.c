#include <stdio.h>

int main() {
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int array[rows][cols];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    // Initialize maxDiagonalElement with the first element of the diagonal
    int maxDiagonalElement = array[0][0];

    // Find the maximum diagonal element
    for (int i = 0; i < rows && i < cols; i++) {
        if (array[i][i] > maxDiagonalElement) {
            maxDiagonalElement = array[i][i];
        }
    }

    printf("The highest diagonal element is: %d\n", maxDiagonalElement);

    return 0;
}
