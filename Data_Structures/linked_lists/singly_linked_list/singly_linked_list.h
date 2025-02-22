#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function declarations
void display(struct Node **head);
void createNode(struct Node **head, struct Node **tail, struct Node *temp);
void insertAtBeginning(struct Node **head, struct Node *newNode);
void insertAtEnd(struct Node **head, struct Node **tail, struct Node *newNode);
void insertAtPosition(struct Node **head, int position, struct Node *newNode);
void deleteFromHead(struct Node **head);
void deleteFromTail(struct Node **head, struct Node **tail);
void deleteAtPosition(struct Node **head, int position2);

#endif