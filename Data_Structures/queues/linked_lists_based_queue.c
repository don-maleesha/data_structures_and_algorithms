#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

// Add data to the queue
void enqueue(struct Node **front, struct Node **rear, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed! Cannot enqueue data.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
    printf("%d enqueued to queue\n", data);
}

// Remove data from the queue
void dequeue(struct Node **front, struct Node **rear) {
    if (*front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        struct Node *temp = *front;
        *front = (*front)->next;

        if (*front == NULL) {
            *rear = NULL;
        }

        printf("%d dequeued from queue\n", temp->data);
        free(temp);
    }
}

// Display the queue
void display(struct Node *front) {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        struct Node *temp = front;
        printf("Queue: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct Node *front = NULL;
    struct Node *rear = NULL;
    int choice, data ;

    while (true) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&front, &rear, data);
                break;
            case 2:
                dequeue(&front, &rear);
                break;
            case 3:
                display(front);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}