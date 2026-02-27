//Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head1 = NULL;
struct Node* head2 = NULL;
void createLinkedList(struct Node** head, int n) {
    struct Node* temp;
    struct Node* newNode;
    
    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        
        if (*head == NULL) {
            *head = newNode;
            temp = *head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
}
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;
    
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1 == temp2) {
            return temp1; 
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return NULL; 
}
int main() {
    int n1, n2;
    printf("Enter the number of nodes for first linked list: ");
    scanf("%d", &n1);
    createLinkedList(&head1, n1);
    
    printf("Enter the number of nodes for second linked list: ");
    scanf("%d", &n2);
    createLinkedList(&head2, n2);
    
    
    if (n1 > 0 && n2 > 0) {
        struct Node* temp1 = head1;
        while (temp1->next != NULL) {
            temp1 = temp1->next;
        }
        temp1->next = head2; 
    }
    
    printf("First Linked List: ");
    displayList(head1);
    
    printf("Second Linked List: ");
    displayList(head2);
    
    struct Node* intersection = findIntersection(head1, head2);
    if (intersection != NULL) {
        printf("Intersection point data: %d\n", intersection->data);
    } else {
        printf("No intersection found.\n");
    }
    
    return 0;
}
