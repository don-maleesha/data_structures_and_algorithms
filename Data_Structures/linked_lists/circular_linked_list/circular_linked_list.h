#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void display(struct Node **head);
void createNode(struct Node **head, struct Node **tail, struct Node *temp);
void insertAtBeginning(struct Node **head, struct Node **tail, struct Node *newNode);
void insertAtEnd(struct Node **head, struct Node **tail, struct Node *newNode);
void insertAtPosition(struct Node **head, struct Node **tail, int position, struct Node *newNode);
void deleteFromHead(struct Node **head, struct Node **tail);
void deleteFromTail(struct Node **head, struct Node **tail);
void deleteAtPosition(struct Node **head, struct Node **tail, int position);
void freeList(struct Node **head);

#endif