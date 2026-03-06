// Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* top = NULL;
void push(int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = top;
    top = newNode;
}
int pop() {
    if (top == NULL) {
        printf("Stack underflow! Cannot pop from an empty stack.\n");
        return -1; 
    } else {
        Node* temp = top;
        int item = temp->data;
        top = top->next;
        free(temp);
        return item;
    }
}
int evaluatePostfix(char* postfix) {
    for (int i = 0; postfix[i] != '\0'; i++) {
        char token = postfix[i];
        if (token >= '0' && token <= '9') {
            push(token - '0'); 
        } else { 
            int val2 = pop();
            int val1 = pop();
            switch (token) {
                case '+':
                    push(val1 + val2);
                    break;
                case '-':
                    push(val1 - val2);
                    break;
                case '*':
                    push(val1 * val2);
                    break;
                case '/':
                    if (val2 != 0) {
                        push(val1 / val2);
                    } else {
                        printf("Division by zero error!\n");
                        return -1; 
                    }
                    break;
            }
        }
    }
    return pop(); 
}
int main() {
    char postfix[100];
    printf("Enter a postfix expression (single-digit operands): ");
    scanf("%s", postfix);
    int result = evaluatePostfix(postfix);
    if (result != -1) {
        printf("The result of the postfix expression is: %d\n", result);
    }
    return 0;
}