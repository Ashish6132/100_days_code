//Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};
struct Node* head = NULL;
void createPolynomial(int n) {
    struct Node* temp;
    struct Node* newNode;
    
    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &newNode->coeff, &newNode->exp);
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
void displayPolynomial(struct Node* head) {
    if (head == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d ", temp->coeff, temp->exp);
        if (temp->next != NULL && temp->next->coeff >= 0) {
            printf("+ ");
        }
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);
    createPolynomial(n);
    
    printf("Polynomial: ");
    displayPolynomial(head);
    
    return 0;
}