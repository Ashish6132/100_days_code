//Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.
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
void deleteFirstOccurrence(int key) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp != NULL) {
        if (temp->data == key) {
            if (prev == NULL) {
                head = temp->next; // Deleting the head node
            } else {
                prev->next = temp->next; 
            }
            free(temp); 
            return; 
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Key %d not found in the linked list.\n", key);
}
void displayList() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    int n, key;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    createLinkedList(n);
    
    printf("Linked list before deletion: ");
    displayList();
    
    printf("Enter the key to delete: ");
    scanf("%d", &key);
    
    deleteFirstOccurrence(key);
    
    printf("Linked list after deletion: ");
    displayList();
    
    return 0;
}
