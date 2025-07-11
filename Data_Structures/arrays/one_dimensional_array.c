#include <stdio.h>
#include <stdlib.h>  // for NULL, malloc, free
#include <stddef.h>  // for NULL definition

#define MAX_SIZE 100

// Function prototypes
void displayArray(int arr[], int size);
int insertElement(int arr[], int *size, int element, int position);
int deleteElement(int arr[], int *size, int position);
int searchElement(int arr[], int size, int element);
void reverseArray(int arr[], int size);
int findMax(int arr[], int size);
int findMin(int arr[], int size);
void sortArray(int arr[], int size);

// Function to display array elements
void displayArray(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty\n");
        return;
    }
    
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element at a specific position
int insertElement(int arr[], int *size, int element, int position) {
    if (*size >= MAX_SIZE) {
        printf("Array is full! Cannot insert element.\n");
        return 0;
    }
    
    if (position < 0 || position > *size) {
        printf("Invalid position! Position should be between 0 and %d\n", *size);
        return 0;
    }
    
    // Shift elements to the right
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[position] = element;
    (*size)++;
    printf("Element %d inserted at position %d\n", element, position);
    return 1;
}

// Function to delete an element from a specific position
int deleteElement(int arr[], int *size, int position) {
    if (*size == 0) {
        printf("Array is empty! Cannot delete element.\n");
        return 0;
    }
    
    if (position < 0 || position >= *size) {
        printf("Invalid position! Position should be between 0 and %d\n", *size - 1);
        return 0;
    }
    
    int deletedElement = arr[position];
    
    // Shift elements to the left
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    (*size)--;
    printf("Element %d deleted from position %d\n", deletedElement, position);
    return 1;
}

// Function to search for an element in the array
int searchElement(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;  // Return the index if found
        }
    }
    return -1;  // Return -1 if not found
}

// Function to reverse the array
void reverseArray(int arr[], int size) {
    int temp;
    for (int i = 0; i < size / 2; i++) {
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
    printf("Array reversed successfully\n");
}

// Function to find maximum element
int findMax(int arr[], int size) {
    if (size == 0) return -1;
    
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to find minimum element
int findMin(int arr[], int size) {
    if (size == 0) return -1;
    
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Function to sort array in ascending order (bubble sort)
void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array sorted successfully\n");
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, element, position, index;
    
    printf("=== One Dimensional Array Operations ===\n");
    
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Display array\n");
        printf("4. Search element\n");
        printf("5. Reverse array\n");
        printf("6. Find maximum\n");
        printf("7. Find minimum\n");
        printf("8. Sort array\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position (0 to %d): ", size);
                scanf("%d", &position);
                insertElement(arr, &size, element, position);
                break;
                
            case 2:
                if (size == 0) {
                    printf("Array is empty!\n");
                } else {
                    printf("Enter position to delete (0 to %d): ", size - 1);
                    scanf("%d", &position);
                    deleteElement(arr, &size, position);
                }
                break;
                
            case 3:
                displayArray(arr, size);
                break;
                
            case 4:
                printf("Enter element to search: ");
                scanf("%d", &element);
                index = searchElement(arr, size, element);
                if (index != -1) {
                    printf("Element %d found at position %d\n", element, index);
                } else {
                    printf("Element %d not found in the array\n", element);
                }
                break;
                
            case 5:
                if (size == 0) {
                    printf("Array is empty!\n");
                } else {
                    reverseArray(arr, size);
                }
                break;
                
            case 6:
                if (size == 0) {
                    printf("Array is empty!\n");
                } else {
                    printf("Maximum element: %d\n", findMax(arr, size));
                }
                break;
                
            case 7:
                if (size == 0) {
                    printf("Array is empty!\n");
                } else {
                    printf("Minimum element: %d\n", findMin(arr, size));
                }
                break;
                
            case 8:
                if (size == 0) {
                    printf("Array is empty!\n");
                } else {
                    sortArray(arr, size);
                }
                break;
                
            case 9:
                printf("Exiting program...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}