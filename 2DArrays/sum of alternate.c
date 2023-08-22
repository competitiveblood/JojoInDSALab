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

    int sum = 0;
    for (int i = 0; i < rows; i += 2) {
        for (int j = 0; j < cols; j++) {
            sum += array[i][j];
        }
    }

    printf("Sum of elements in alternate rows: %d\n", sum);

    return 0;
}
