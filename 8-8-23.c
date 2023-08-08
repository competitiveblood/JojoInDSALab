#include<stdio.h>
#include<stdlib.h>

// initialization 
void initializeArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10; // Assign a random value between 0 and 99
    }
}

// addition 
int arraySum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// multiplication
int arrayProduct(int arr[], int size) {
    int product = 1;
    for (int i = 0; i < size; i++) {
        product *= arr[i];
    }
    return product;
}

// searching element 
int searchArray(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1;
}

int main() {
    const int SIZE = 10;
    int myArray[SIZE];

    // Initialize the array
    initializeArray(myArray, SIZE);

    // Print the initial array
    printf("Initial array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", myArray[i]);
    }
    printf("\n");

    // Calculate and print the sum of array elements
    int sum = arraySum(myArray, SIZE);
    printf("Sum of array elements: %d\n", sum);

    // Calculate and print the product of array elements
    int product = arrayProduct(myArray, SIZE);
    printf("Product of array elements: %d\n", product);

    // Search for an element in the array
    int target = 9; // Element to search for
    int index = searchArray(myArray, SIZE, target);
    if (index != -1) {
        printf("Element %d found at index %d\n", target, index);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}
