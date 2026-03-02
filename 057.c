//Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void createLinkedList(int n) {
    struct Node* temp;
    struct Node* newNode;
    
    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
}
void rotateRight(struct Node** head, int k) {
    if (*head == NULL || k <= 0) {
        return;
    }
    
    struct Node* temp = *head;
    int length = 1;
    
    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }
    
    temp->next = *head;
    k = k % length; 
    
    for (int i = 0; i < length - k; i++) {
        temp = temp->next;
    }
    
    *head = temp->next; 
    temp->next = NULL; 
}
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    int n, k;
    printf("Enter the number of nodes for linked list: ");
    scanf("%d", &n);
    createLinkedList(n);
    
    printf("Original Linked List: ");
    displayList(head);
    
    printf("Enter the number of places to rotate right: ");
    scanf("%d", &k);
    
    rotateRight(&head, k);
    
    printf("Rotated Linked List: ");
    displayList(head);
    
    return 0;
}