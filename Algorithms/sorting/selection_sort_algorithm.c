#include <stdio.h>

// Selection sort algorithm
// Sorts an array by repeatedly finding the minimum element from the unsorted part of the array and putting it at the beginning
void selection_sort(int arr[], int n) {
    int i, j;
    
    // Traverse through the array
    for (i = 0; i < n - 1; i++) {
        int min_index = i; // Find the minimum element in the unsorted part of the array

        // Traverse through the unsorted part of the array
        for (j = i + 1; j < n; j++) {

            // If the current element is smaller than the minimum element, update the minimum element
            if (arr[j] < arr[min_index]) {

                min_index = j; // Update the index of minimum element
            }
        }

        // Swap the minimum element with the first element of the unsorted part of the array
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    selection_sort(arr, n);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}