#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

int queue[SIZE];
int front = -1, rear = -1;

// Check if queue is full
bool isFull() {
    if (front == 0 && rear == SIZE - 1) {
        return true;
    }
    return false;
}

// Check if queue is empty
bool isEmpty() {
    if (front == -1) {
        return true;
    }
    return false;
}

// Add data to queue
void enqueue(int data) {
    if (isFull()) {
        printf("Queue is full\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = data;
        printf("%d enqueued to queue\n", data);
    }
}

// Remove data from queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("%d dequeued from queue\n", queue[front]);
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }
}

// Display queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        int i;
        for (i = front; i <= rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}

int main() {
    int choice, data;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}