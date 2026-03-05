//Implement a stack data structure using an array with the following operations: push, pop, and display.
#include <stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int value) {
    if (top >= MAX - 1) {
        printf("Stack overflow! Cannot push %d\n", value);
    } else {
        stack[++top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}
void pop() {
    if (top < 0) {
        printf("Stack underflow! Cannot pop from an empty stack.\n");
    } else {
        int value = stack[top--];
        printf("Popped %d from the stack.\n", value);
    }
}
void display() {
    if (top < 0) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
int main() {
    int choice, value;
    while (1) {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}