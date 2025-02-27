#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

int stack[SIZE];
int Tos = -1; // Top of stack

// Check if stack is empty
bool isEmpty(){
    if (Tos == -1){
        return true;
    } else {
        return false;
    }      
}

// Check if stack is full
bool isFull(){
    if (Tos == SIZE - 1){
        return true;
    } else {
        return false;
    }
}

// Push data to stack
void push(int data){
    if(!isFull()){
        Tos++;
        stack[Tos] = data;
        printf("%d pushed to stack\n", data);
    } else {
        printf("Stack is full\n");
    }
}

// Pop data from stack
void pop(){
    if(!isEmpty()){
        printf("%d popped from stack\n", stack[Tos]);
        Tos--;
    } else {
        printf("Stack is empty\n");
    }
}

// Display stack
void display(){
    if(isEmpty()){
        printf("Stack is empty\n");
        return;
    }
    int i;
    for(i = Tos; i >= 0; i--){
        printf("%d\n", stack[i]);
    }
}

// Peek Tos element
void peek(){
    if(isEmpty()){
        printf("Stack is empty\n");
        return;
    }
    printf("Tos element is %d\n", stack[Tos]);
}

int main(){

    int choice, data;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Peek Top Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFull()) {
                    printf("Stack is full. Cannot push more elements.\n");
                } else {
                    printf("Enter data to push: ");
                    scanf("%d", &data);
                    push(data);
                }
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;

    return 0;

}