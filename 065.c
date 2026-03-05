//Convert an infix expression to postfix notation using stack.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack overflow! Cannot push %c\n", item);
    } else {
        stack[++top] = item;
    }
}
char pop() {
    if (top < 0) {
        printf("Stack underflow! Cannot pop from an empty stack.\n");
        return '\0';
    } else {
        return stack[top--];
    }
}
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}
void infixToPostfix(char* infix, char* postfix) {
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];
        if (token >= 'a' && token <= 'z' || token >= 'A' && token <= 'Z') {
            postfix[j++] = token;
        } else if (token == '(') {
            push(token);
        } else if (token == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // Pop the '('
        } else { // Operator
            while (top >= 0 && precedence(stack[top]) >= precedence(token)) {
                postfix[j++] = pop();
            }
            push(token);
        }
    }
    while (top >= 0) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}
int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0'; // Remove newline character
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}