#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Push an element onto the stack
void push(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed! Cannot insert node.\n");
        return;
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    printf("%d pushed to the stack.\n", data);
}

// Pop an element from the stack
void pop(struct Node** head) {
    if (*head == NULL) {
        printf("The stack is empty. Nothing to pop.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    printf("%d popped from the stack.\n", temp->data);
    free(temp);
}

// Display the stack
void display(struct Node* head) {
    if (head == NULL) {
        printf("The stack is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Peek at the top element of the stack
void peek(struct Node* head) {
    if (head == NULL) {
        printf("The stack is empty.\n");
        return;
    }
    printf("Top element is %d\n", head->data);
}

int main() {
    struct Node* head = NULL; // Initialize head to NULL
    int choice, data;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(&head, data);
                break;
            case 2:
                pop(&head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                peek(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}