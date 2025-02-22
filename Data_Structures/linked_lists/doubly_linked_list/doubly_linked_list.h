#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function prototypes
void displayList(struct Node *head);
void insertAtBeginning(struct Node **head, struct Node **tail, int data);
void insertAtEnd(struct Node **head, struct Node **tail, int data);
void insertAtPosition(struct Node **head, struct Node **tail, int position, int data);
void deleteFromBeginning(struct Node **head, struct Node **tail);
void deleteFromEnd(struct Node **head, struct Node **tail);
void deleteAtPosition(struct Node **head, struct Node **tail, int position);
void freeList(struct Node **head);

#endif // DOUBLY_LINKED_LIST_H