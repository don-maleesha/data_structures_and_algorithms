#include "circular_linked_list.h"

// Function to display the list
void displayList(struct Node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Function to create a new node and add it to the list
void createNode(struct Node **head, struct Node **tail, struct Node *temp) {
    if (*head == NULL && *tail == NULL) {
        *head = temp;
        *tail = temp;
        temp->next = *head; // Make it circular
    } else {
        (*tail)->next = temp;
        *tail = temp;
        temp->next = *head; // Make it circular
    }
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node **head, struct Node **tail, struct Node *newNode) {
    if (newNode == NULL) {
        printf("Memory allocation failed! Cannot insert node.\n");
        return;
    }

    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
        newNode->next = *head; // Make it circular
    } else {
        newNode->next = *head;
        *head = newNode;
        (*tail)->next = *head; // Update tail's next to new head
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
        newNode->next = *head; // Make it circular
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
        newNode->next = *head; // Make it circular
    }

    printf("\nData entered in the list after the insertion at the end: ");
    display(head);
}

// Function to insert a new node at a specific position in the list
void insertAtPosition(struct Node **head, struct Node **tail, int position, struct Node *newNode) {
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
        (*tail)->next = *head; // Update tail's next to new head
        printf("\nData entered in the list after the insertion at position %d: ", position);
        display(head);
        return;
    }

    // Traverse to the node before the specified position
    while (i < position - 1 && temp->next != *head) {
        temp = temp->next;
        i++;
    }

    if (temp->next == *head && i < position - 1) {
        printf("The list has less elements than the position specified.\n");
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == *head) {
            *tail = newNode; // Update tail if newNode is inserted at the end
        }
    }

    printf("\nData entered in the list after the insertion at position %d: ", position);
    display(head);
}

// Function to delete a node from the beginning of the list
void deleteFromHead(struct Node **head, struct Node **tail) {
    if (*head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return;
    }

    struct Node *temp = *head;
    if (*head == *tail) {
        // Only one node in the list
        *head = NULL;
        *tail = NULL;
    } else {
        *head = (*head)->next;
        (*tail)->next = *head; // Update tail's next to new head
    }
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

    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        // Only one node in the list
        *head = NULL;
        *tail = NULL;
    } else {
        prev->next = *head; // Update prev node's next to head
        *tail = prev; // Update tail
    }

    free(temp);

    printf("\nList after the deletion of the last node: ");
    display(head);
}

// Function to delete a node from a specific position in the list
void deleteAtPosition(struct Node **head, struct Node **tail, int position) {
    if (*head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position. Position must be greater than 0.\n");
        return;
    }

    struct Node *temp = *head;
    struct Node *prev = NULL;
    int i;

    // Handle deletion at the beginning
    if (position == 1) {
        if (*head == *tail) {
            // Only one node in the list
            *head = NULL;
            *tail = NULL;
        } else {
            *head = temp->next;
            (*tail)->next = *head; // Update tail's next to new head
        }
        free(temp);
        printf("\nList after deletion of node at position %d: ", position);
        display(head);
        return;
    }

    // Traverse to the node at the specified position
    for (i = 1; temp->next != *head && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp->next == *head && i < position) {
        printf("The list has less elements than the position specified.\n");
        return;
    }

    prev->next = temp->next;
    if (temp == *tail) {
        *tail = prev; // Update tail if the last node is deleted
    }
    free(temp);

    printf("\nList after deletion of node at position %d: ", position);
    display(head);
}

// Function to free the entire list
void freeList(struct Node **head) {
    if (*head == NULL) {
        return;
    }

    struct Node *current = *head;
    struct Node *next;

    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != *head);

    *head = NULL;
}