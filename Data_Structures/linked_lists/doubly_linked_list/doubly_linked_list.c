#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

// Function to create a new node and add it to the end of the list
void createNode(struct Node **head, struct Node **tail, struct Node *newNode) {
    if (*head == NULL) {
        // If the list is empty, the new node becomes the head and tail
        *head = newNode;
        *tail = newNode;
    } else {
        // Otherwise, add the new node to the end of the list
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

int main() {
    int i, n, position, position2;

    struct Node *head = NULL;
    struct Node *tail = NULL;
    struct Node *temp = NULL;
    struct Node *newNode = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of nodes. Exiting program.\n");
        return 1;
    }

    printf("\n");

    // Create n nodes and add them to the list
    for (i = 0; i < n; i++) {
        temp = (struct Node *)malloc(sizeof(struct Node));

        if (temp == NULL) {
            printf("Memory allocation failed!\n");
            freeList(&head);
            return 1;
        }

        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &temp->data);
        temp->next = NULL;
        temp->prev = NULL;

        createNode(&head, &tail, temp);
    }

    printf("\n");

    // Display the list
    printf("Data entered in the list: ");
    display(&head);

    // Insert a new node at the beginning of the list
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        freeList(&head);
        return 1;
    }

    printf("\nEnter data to be inserted at the beginning: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    newNode->prev = NULL;

    insertAtBeginning(&head, &tail, newNode);

    // Insert a new node at the end of the list
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        freeList(&head);
        return 1;
    }

    printf("\nEnter data to be inserted at the end: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    newNode->prev = NULL;

    insertAtEnd(&head, &tail, newNode);

    // Insert a new node at a specific position in the list
    printf("\nEnter the position where you want to insert a new node: ");
    scanf("%d", &position);

    if (position < 1) {
        printf("Invalid position. Position must be greater than 0.\n");
    } else {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            freeList(&head);
            return 1;
        }

        printf("\nEnter data to be inserted at position %d: ", position);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        newNode->prev = NULL;

        insertAtPosition(&head, &tail, position, newNode);
    }

    // Delete a node from the beginning of the list
    deleteFromHead(&head, &tail);

    // Delete a node from the end of the list
    deleteFromTail(&head, &tail);

    // Delete a node from a specific position in the list
    printf("\nEnter the position from where you want to delete a node: ");
    scanf("%d", &position2);

    if (position2 < 1) {
        printf("Invalid position. Position must be greater than 0.\n");
    } else {
        deleteAtPosition(&head, &tail, position2);
    }

    // Free the allocated memory
    freeList(&head);

    return 0;
}