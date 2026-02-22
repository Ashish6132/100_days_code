//Count Nodes in Linked List
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
int countNodes() {
    struct Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    createLinkedList(n);
    
    int nodeCount = countNodes();
    printf("Number of nodes in the linked list: %d\n", nodeCount);
    
    return 0;
}
