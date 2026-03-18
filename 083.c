/*Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node *front = NULL, *rear = NULL;


void enqueue(int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue() {
    if (front == NULL) return -1;

    Node* temp = front;
    int val = temp->data;
    front = front->next;

    if (front == NULL) rear = NULL;

    free(temp);
    return val;
}


int main() {
    int n;
    scanf("%d", &n);

    char op[20];
    int x;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (strcmp(op, "enqueue") == 0) {
            scanf("%d", &x);
            enqueue(x);
        }
        else if (strcmp(op, "dequeue") == 0) {
            printf("%d\n", dequeue());
        }
    }

    return 0;
}