//Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void createCircularLinkedList(int n) {
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
    temp->next = head; 
}
void displayCircularList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("NULL\n");
}
int main() {
    int n;
    printf("Enter the number of nodes for circular linked list: ");
    scanf("%d", &n);
    createCircularLinkedList(n);
    
    printf("Circular Linked List: ");
    displayCircularList(head);
    
    return 0;
}