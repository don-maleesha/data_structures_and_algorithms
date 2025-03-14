#include <stdio.h>

// Bubble sort algorithm
// Sorts an array by repeatedly swapping adjacent elements if they are in the wrong order
void bubble_sort(int arr[], int n) {
    int i, j, temp;

    // Traverse through the array
    for (i = 0; i < n - 1; i++) {
        // Flag to check if any swapping is done in the current pass
        int swapped = 0;

        // Traverse through the unsorted part of the array
        for (j = 0; j < n - i - 1; j++) {
            // If the current element is greater than the next element, swap them
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // Set the flag to true
            }
        }

        // If no swapping is done in the current pass, the array is already sorted
        if (swapped == 0) {
            break;
        }
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, n);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}