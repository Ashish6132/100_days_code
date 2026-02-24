// Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct Node* mergedHead = NULL;
    struct Node* mergedTail = NULL;

    while (list1 != NULL && list2 != NULL) {
        struct Node* temp = NULL;
        if (list1->data <= list2->data) {
            temp = createNode(list1->data);
            list1 = list1->next;
        } else {
            temp = createNode(list2->data);
            list2 = list2->next;
        }

        if (mergedHead == NULL) {
            mergedHead = temp;
            mergedTail = temp;
        } else {
            mergedTail->next = temp;
            mergedTail = mergedTail->next;
        }
    }

    while (list1 != NULL) {
        struct Node* temp = createNode(list1->data);
        if (mergedHead == NULL) {
            mergedHead = temp;
            mergedTail = temp;
        } else {
            mergedTail->next = temp;
            mergedTail = mergedTail->next;
        }
        list1 = list1->next;
    }

    while (list2 != NULL) {
        struct Node* temp = createNode(list2->data);
        if (mergedHead == NULL) {
            mergedHead = temp;
            mergedTail = temp;
        } else {
            mergedTail->next = temp;
            mergedTail = mergedTail->next;
        }
        list2 = list2->next;
    }

    return mergedHead;
}
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    struct Node* list1 = createNode(1);
    list1->next = createNode(3);
    list1->next->next = createNode(5);

    struct Node* list2 = createNode(2);
    list2->next = createNode(4);
    list2->next->next = createNode(6);

    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    struct Node* mergedList = mergeSortedLists(list1, list2);
    printf("Merged List: ");
    printList(mergedList);

    return 0;
}
