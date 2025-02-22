#include "singly_linked_list.h"

int main() {
    int i, n, position, position2;

    struct Node *head, *temp, *tail, *newNode, *newNode2, *newNode3;
    head = NULL;
    tail = NULL;

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
            return 1;
        }

        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &temp->data);
        temp->next = NULL;

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
        return 1;
    }

    printf("\nEnter data to be inserted at the beginning: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    insertAtBeginning(&head, newNode);

    // Insert a new node at the end of the list
    newNode2 = (struct Node *)malloc(sizeof(struct Node));
    if (newNode2 == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("\nEnter data to be inserted at the end: ");
    scanf("%d", &newNode2->data);
    newNode2->next = NULL;

    insertAtEnd(&head, &tail, newNode2);

    // Insert a new node at a specific position in the list
    printf("\nEnter the position where you want to insert a new node: ");
    scanf("%d", &position);

    if (position < 1) {
        printf("Invalid position. Position must be greater than 0.\n");
    } else {
        newNode3 = (struct Node *)malloc(sizeof(struct Node));
        if (newNode3 == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("\nEnter data to be inserted at position %d: ", position);
        scanf("%d", &newNode3->data);
        newNode3->next = NULL;

        insertAtPosition(&head, position, newNode3);
    }

    // Delete a node from the beginning of the list
    deleteFromHead(&head);

    // Delete a node from the end of the list
    deleteFromTail(&head, &tail);

    // Delete a node from a specific position in the list
    printf("\nEnter the position from where you want to delete a node: ");
    scanf("%d", &position2);

    if (position2 < 1) {
        printf("Invalid position. Position must be greater than 0.\n");
    } else {
        deleteAtPosition(&head, position2);
    }

    // Free the allocated memory
    struct Node *current = head;
    struct Node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}