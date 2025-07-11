#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dynamic Array Structure
typedef struct {
    int *data;          // Pointer to the array data
    size_t size;        // Current number of elements
    size_t capacity;    // Maximum capacity before reallocation
} DynamicArray;

// Function prototypes
DynamicArray* create_dynamic_array(size_t initial_capacity);
DynamicArray* create_dynamic_array_calloc(size_t initial_capacity);
void destroy_dynamic_array(DynamicArray *arr);
int resize_array(DynamicArray *arr, size_t new_capacity);
int insert_at_end(DynamicArray *arr, int value);
int insert_at_index(DynamicArray *arr, size_t index, int value);
int delete_at_end(DynamicArray *arr);
int delete_at_index(DynamicArray *arr, size_t index);
int get_element(DynamicArray *arr, size_t index);
int set_element(DynamicArray *arr, size_t index, int value);
int find_element(DynamicArray *arr, int value);
void print_array(DynamicArray *arr);
void print_array_info(DynamicArray *arr);
void clear_array(DynamicArray *arr);

// Create a new dynamic array with initial capacity
DynamicArray* create_dynamic_array(size_t initial_capacity) {
    if (initial_capacity == 0) {
        initial_capacity = 1; // Minimum capacity
    }
    
    DynamicArray *arr = (DynamicArray*)malloc(sizeof(DynamicArray));
    if (!arr) {
        printf("Error: Memory allocation failed for dynamic array structure\n");
        return NULL;
    }
    
    arr->data = (int*)malloc(initial_capacity * sizeof(int));
    if (!arr->data) {
        printf("Error: Memory allocation failed for array data\n");
        free(arr);
        return NULL;
    }
    
    arr->size = 0;
    arr->capacity = initial_capacity;
    
    printf("Dynamic array created with initial capacity: %zu\n", initial_capacity);
    return arr;
}

// Create a new dynamic array using calloc (initializes to zero)
DynamicArray* create_dynamic_array_calloc(size_t initial_capacity) {
    if (initial_capacity == 0) {
        initial_capacity = 1; // Minimum capacity
    }
    
    // Using malloc for the structure
    DynamicArray *arr = (DynamicArray*)malloc(sizeof(DynamicArray));
    if (!arr) {
        printf("Error: Memory allocation failed for dynamic array structure\n");
        return NULL;
    }
    
    // Using calloc for the data array - initializes all elements to 0
    arr->data = (int*)calloc(initial_capacity, sizeof(int));
    if (!arr->data) {
        printf("Error: Memory allocation failed for array data\n");
        free(arr);
        return NULL;
    }
    
    arr->size = 0;
    arr->capacity = initial_capacity;
    
    printf("Dynamic array created with calloc, initial capacity: %zu (all elements initialized to 0)\n", initial_capacity);
    return arr;
}

// Destroy the dynamic array and free memory
void destroy_dynamic_array(DynamicArray *arr) {
    if (arr) {
        if (arr->data) {
            free(arr->data);
        }
        free(arr);
        printf("Dynamic array destroyed and memory freed\n");
    }
}

// Resize the array (internal function)
int resize_array(DynamicArray *arr, size_t new_capacity) {
    if (!arr) return 0;
    
    int *new_data = (int*)realloc(arr->data, new_capacity * sizeof(int));
    if (!new_data) {
        printf("Error: Memory reallocation failed\n");
        return 0;
    }
    
    arr->data = new_data;
    arr->capacity = new_capacity;
    printf("Array resized to capacity: %zu\n", new_capacity);
    return 1;
}

// Insert element at the end of the array
int insert_at_end(DynamicArray *arr, int value) {
    if (!arr) return 0;
    
    // Check if we need to resize
    if (arr->size >= arr->capacity) {
        if (!resize_array(arr, arr->capacity * 2)) {
            return 0;
        }
    }
    
    arr->data[arr->size] = value;
    arr->size++;
    printf("Inserted %d at end. New size: %zu\n", value, arr->size);
    return 1;
}

// Insert element at a specific index
int insert_at_index(DynamicArray *arr, size_t index, int value) {
    if (!arr) return 0;
    
    if (index > arr->size) {
        printf("Error: Index %zu out of bounds (size: %zu)\n", index, arr->size);
        return 0;
    }
    
    // Check if we need to resize
    if (arr->size >= arr->capacity) {
        if (!resize_array(arr, arr->capacity * 2)) {
            return 0;
        }
    }
    
    // Shift elements to the right
    for (size_t i = arr->size; i > index; i--) {
        arr->data[i] = arr->data[i - 1];
    }
    
    arr->data[index] = value;
    arr->size++;
    printf("Inserted %d at index %zu. New size: %zu\n", value, index, arr->size);
    return 1;
}

// Delete element from the end
int delete_at_end(DynamicArray *arr) {
    if (!arr || arr->size == 0) {
        printf("Error: Cannot delete from empty array\n");
        return 0;
    }
    
    int deleted_value = arr->data[arr->size - 1];
    arr->size--;
    
    // Shrink array if it's using less than 1/4 of capacity
    if (arr->size > 0 && arr->size <= arr->capacity / 4) {
        resize_array(arr, arr->capacity / 2);
    }
    
    printf("Deleted %d from end. New size: %zu\n", deleted_value, arr->size);
    return 1;
}

// Delete element at a specific index
int delete_at_index(DynamicArray *arr, size_t index) {
    if (!arr || arr->size == 0) {
        printf("Error: Cannot delete from empty array\n");
        return 0;
    }
    
    if (index >= arr->size) {
        printf("Error: Index %zu out of bounds (size: %zu)\n", index, arr->size);
        return 0;
    }
    
    int deleted_value = arr->data[index];
    
    // Shift elements to the left
    for (size_t i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    
    arr->size--;
    
    // Shrink array if it's using less than 1/4 of capacity
    if (arr->size > 0 && arr->size <= arr->capacity / 4) {
        resize_array(arr, arr->capacity / 2);
    }
    
    printf("Deleted %d from index %zu. New size: %zu\n", deleted_value, index, arr->size);
    return 1;
}

// Get element at a specific index
int get_element(DynamicArray *arr, size_t index) {
    if (!arr || index >= arr->size) {
        printf("Error: Index %zu out of bounds (size: %zu)\n", index, arr->size);
        return -1; // Return -1 to indicate error
    }
    
    return arr->data[index];
}

// Set element at a specific index
int set_element(DynamicArray *arr, size_t index, int value) {
    if (!arr || index >= arr->size) {
        printf("Error: Index %zu out of bounds (size: %zu)\n", index, arr->size);
        return 0;
    }
    
    int old_value = arr->data[index];
    arr->data[index] = value;
    printf("Updated element at index %zu from %d to %d\n", index, old_value, value);
    return 1;
}

// Find the first occurrence of an element
int find_element(DynamicArray *arr, int value) {
    if (!arr) return -1;
    
    for (size_t i = 0; i < arr->size; i++) {
        if (arr->data[i] == value) {
            printf("Element %d found at index %zu\n", value, i);
            return (int)i;
        }
    }
    
    printf("Element %d not found in array\n", value);
    return -1;
}

// Print all elements in the array
void print_array(DynamicArray *arr) {
    if (!arr) {
        printf("Array is NULL\n");
        return;
    }
    
    if (arr->size == 0) {
        printf("Array is empty\n");
        return;
    }
    
    printf("Array elements: [");
    for (size_t i = 0; i < arr->size; i++) {
        printf("%d", arr->data[i]);
        if (i < arr->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Print array information (size, capacity)
void print_array_info(DynamicArray *arr) {
    if (!arr) {
        printf("Array is NULL\n");
        return;
    }
    
    printf("Array Info - Size: %zu, Capacity: %zu, Load Factor: %.2f%%\n", 
           arr->size, arr->capacity, 
           arr->capacity > 0 ? (double)arr->size / arr->capacity * 100 : 0.0);
}

// Clear array by resetting size to 0 and using free/calloc for complete memory refresh
void clear_array(DynamicArray *arr) {
    if (!arr) return;
    
    printf("Clearing array - using free() and calloc() to reinitialize memory...\n");
    
    // Free the current data
    free(arr->data);
    
    // Reallocate using calloc to initialize all elements to 0
    arr->data = (int*)calloc(arr->capacity, sizeof(int));
    if (!arr->data) {
        printf("Error: Memory allocation failed during clear operation\n");
        return;
    }
    
    arr->size = 0;
    printf("Array cleared and memory reinitialized with calloc\n");
}

// Main function to demonstrate dynamic array operations
int main() {
    printf("=== Dynamic Array Implementation Demo ===\n");
    printf("Demonstrating malloc, calloc, realloc, and free operations\n\n");
    
    // Test 1: Create array with malloc (uninitialized memory)
    printf("--- Test 1: malloc() - Creating array with uninitialized memory ---\n");
    DynamicArray *arr1 = create_dynamic_array(2);
    if (!arr1) {
        return 1;
    }
    
    // Test insertions (shows automatic realloc)
    printf("\n--- Testing Insertions (triggers realloc()) ---\n");
    insert_at_end(arr1, 10);
    insert_at_end(arr1, 20);
    insert_at_end(arr1, 30);  // This will trigger realloc to double capacity
    print_array(arr1);
    print_array_info(arr1);
    
    insert_at_index(arr1, 1, 15);
    print_array(arr1);
    print_array_info(arr1);
    
    // Test access operations
    printf("\n--- Testing Access Operations ---\n");
    printf("Element at index 2: %d\n", get_element(arr1, 2));
    set_element(arr1, 2, 25);
    print_array(arr1);
    
    // Test search
    printf("\n--- Testing Search ---\n");
    find_element(arr1, 25);
    find_element(arr1, 100);
    
    // Test deletions (shows automatic realloc shrinking)
    printf("\n--- Testing Deletions (triggers realloc() shrinking) ---\n");
    delete_at_index(arr1, 1);
    print_array(arr1);
    print_array_info(arr1);
    
    delete_at_end(arr1);
    delete_at_end(arr1);  // This should trigger shrinking
    print_array(arr1);
    print_array_info(arr1);
    
    // Test 2: Create array with calloc (zero-initialized memory)
    printf("\n--- Test 2: calloc() - Creating array with zero-initialized memory ---\n");
    DynamicArray *arr2 = create_dynamic_array_calloc(3);
    if (!arr2) {
        destroy_dynamic_array(arr1);
        return 1;
    }
    
    printf("Calloc initialized array (should show zeros if we had elements):\n");
    print_array(arr2);
    print_array_info(arr2);
    
    // Add some elements and then clear with calloc
    insert_at_end(arr2, 100);
    insert_at_end(arr2, 200);
    insert_at_end(arr2, 300);
    printf("After adding elements:\n");
    print_array(arr2);
    
    // Test clear function (demonstrates free + calloc)
    printf("\n--- Test 3: free() + calloc() - Clearing and reinitializing memory ---\n");
    clear_array(arr2);
    print_array(arr2);
    print_array_info(arr2);
    
    // Test edge cases
    printf("\n--- Testing Edge Cases ---\n");
    printf("Attempting to access invalid index:\n");
    get_element(arr1, 10);
    
    printf("Attempting to delete from index beyond bounds:\n");
    delete_at_index(arr1, 10);
    
    // Test 4: Demonstrate all memory functions summary
    printf("\n--- Memory Management Summary ---\n");
    printf("1. malloc() - Used for initial allocation of array structure and data\n");
    printf("2. calloc() - Used for zero-initialized allocation and clearing\n");
    printf("3. realloc() - Used for resizing array (growing/shrinking)\n");
    printf("4. free() - Used for deallocating memory when destroying or clearing\n");
    
    // Clean up (demonstrates free)
    printf("\n--- Test 4: free() - Cleaning up memory ---\n");
    destroy_dynamic_array(arr1);
    destroy_dynamic_array(arr2);
    
    printf("\n=== Demo Complete ===\n");
    printf("All memory has been properly freed!\n");
    return 0;
}