//Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.
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
int countOccurrences(int key) {
    struct Node* temp = head;
    int count = 0;

    while (temp != NULL) {
        if (temp->data == key) {
            count++;
        }
        temp = temp->next;
    }
    return count;
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
    
    printf("Enter the key to count occurrences: ");
    scanf("%d", &key);
    
    int occurrences = countOccurrences(key);
    printf("The key %d occurs %d times in the linked list.\n", key, occurrences);
    
    return 0;
}