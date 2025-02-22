#include "singly_linked_list.h"

// Function to display the list
void display(struct Node **head) {
    struct Node *temp = *head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to create a new node and add it to the list
void createNode(struct Node **head, struct Node **tail, struct Node *temp) {
    if (*head == NULL && *tail == NULL) {
        *head = temp;
        *tail = temp;
    } else {
        (*tail)->next = temp;
        *tail = temp;
    }
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node **head, struct Node *newNode) {
    if (newNode == NULL) {
        printf("Memory allocation failed! Cannot insert node.\n");
        return;
    }

    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        *head = newNode;
    }

    printf("\nData entered in the list after the insertion at the beginning: ");
    display(head);
}

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node **head, struct Node **tail, struct Node *newNode) {
    if (newNode == NULL) {
        printf("Memory allocation failed! Cannot insert node.\n");
        return;
    }

    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }

    printf("\nData entered in the list after the insertion at the end: ");
    display(head); 
}

// Function to insert a new node at a specific position in the list
void insertAtPosition(struct Node **head, int position, struct Node *newNode) {
    if (newNode == NULL) {
        printf("Memory allocation failed! Cannot insert node.\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position. Position must be greater than 0.\n");
        return;
    }

    struct Node *temp = *head;
    int i = 1;

    // Handle insertion at the beginning
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        printf("\nData entered in the list after the insertion at position %d: ", position);
        display(head);
        return;
    }

    // Traverse to the node before the specified position
    while (i < position - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("The list has less elements than the position specified.\n");
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("\nData entered in the list after the insertion at position %d: ", position);
    display(head);
}

// Function to delete a node from the beginning of the list
void deleteFromHead(struct Node **head) {
    if (*head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return;
    }

    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);

    printf("\nList after the deletion of the first node: ");
    display(head);
}

// Function to delete a node from the end of the list
void deleteFromTail(struct Node **head, struct Node **tail) {
    if (*head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return;
    }

    struct Node *temp = *head;
    struct Node *prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        // Only one node in the list
        *head = NULL;
        *tail = NULL;
    } else {
        prev->next = NULL;
        *tail = prev;
    }

    free(temp);

    printf("\nList after the deletion of the last node: ");
    display(head);
}

// Function to delete a node from a specific position in the list
void deleteAtPosition(struct Node **head, int position2) {
    if (*head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return;
    }

    if (position2 < 1) {
        printf("Invalid position. Position must be greater than 0.\n");
        return;
    }

    struct Node *temp = *head;
    struct Node *prev = NULL;
    int i;

    // Handle deletion at the beginning
    if (position2 == 1) {
        *head = temp->next;
        free(temp);
        printf("\nList after deletion of node at position %d: ", position2);
        display(head);
        return;
    }

    // Traverse to the node at the specified position
    for (i = 1; temp != NULL && i < position2; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("The list has less elements than the position specified.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("\nList after deletion of node at position %d: ", position2);
    display(head);
}