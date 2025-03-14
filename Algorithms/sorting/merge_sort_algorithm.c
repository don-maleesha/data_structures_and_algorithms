#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted subarrays
void merge(int array[], int left, int middle, int right) {
    int i, j, k;
    int left_size = middle - left + 1; // Size of the left subarray
    int right_size = right - middle;  // Size of the right subarray

    // Create temporary arrays for left and right subarrays
    int *left_array = (int *)malloc(left_size * sizeof(int));
    int *right_array = (int *)malloc(right_size * sizeof(int));

    // Check if memory allocation was successful
    if (left_array == NULL || right_array == NULL) {
        printf("Memory allocation failed!\n");
        exit(1); // Exit the program with an error code
    }

    // Copy data to temporary arrays left_array[] and right_array[]
    for (i = 0; i < left_size; i++)
        left_array[i] = array[left + i];
    for (j = 0; j < right_size; j++)
        right_array[j] = array[middle + 1 + j];

    // Merge the temporary arrays back into array[left..right]
    i = 0; // Initial index of the left subarray
    j = 0; // Initial index of the right subarray
    k = left; // Initial index of the merged subarray

    while (i < left_size && j < right_size) {
        if (left_array[i] <= right_array[j]) {
            array[k] = left_array[i];
            i++;
        } else {
            array[k] = right_array[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left_array[], if any
    while (i < left_size) {
        array[k] = left_array[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right_array[], if any
    while (j < right_size) {
        array[k] = right_array[j];
        j++;
        k++;
    }

    // Free the temporary arrays
    free(left_array);
    free(right_array);
}

// Merge Sort function
void mergeSort(int array[], int left, int right) {
    if (left < right) {
        // Same as (left + right) / 2, but avoids overflow for large left and right
        int middle = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        // Merge the sorted halves
        merge(array, left, middle, right);
    }
}

int main() {
    int array[] = {12, 11, 13, 5, 6, 7};
    int array_size = sizeof(array) / sizeof(array[0]);

    // Print the original array
    printf("Original array: \n");
    for (int i = 0; i < array_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Perform merge sort
    mergeSort(array, 0, array_size - 1);

    // Print the sorted array
    printf("Sorted array: \n");
    for (int i = 0; i < array_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}