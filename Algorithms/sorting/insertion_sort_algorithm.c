#include <stdio.h>

// Insertion sort algorithm
// Sorts an array by dividing it into a sorted and an unsorted part, and inserting elements from the unsorted part into the sorted part
void insertion_sort(int arr[], int n) {
    int i, j, temp;

    // Traverse through the array
    for (i = 1; i < n; i++) {
        temp = arr[i]; // Select the temp element to be inserted into the sorted part

        j = i - 1; // Initialize j to the last element of the sorted part

        // Move elements of the sorted part that are greater than the temp to one position ahead of their current position
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j]; // Shift the element to the right
            j = j - 1; // Move to the previous element
        }

        arr[j + 1] = temp; // Insert the temp element into its correct position in the sorted part

    }

}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr, n);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}