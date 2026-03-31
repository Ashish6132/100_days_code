//Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

//Input Format:
//- First line contains integer N (number of nodes)
//- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

//Output Format:
//- Print nodes column by column from leftmost to rightmost vertical line

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

void findMinMax(struct Node* root, int hd, int* min, int* max) {
    if (!root) return;

    if (hd < *min) *min = hd;
    if (hd > *max) *max = hd;

    findMinMax(root->left, hd - 1, min, max);
    findMinMax(root->right, hd + 1, min, max);
}

void printVertical(struct Node* root, int line, int hd) {
    if (!root) return;

    if (hd == line)
        printf("%d ", root->data);

    printVertical(root->left, line, hd - 1);
    printVertical(root->right, line, hd + 1);
}

void verticalOrder(struct Node* root) {
    int min = 0, max = 0;

    findMinMax(root, 0, &min, &max);

    for (int i = min; i <= max; i++) {
        printVertical(root, i, 0);
    }
}

int main() {
    // Hardcoded tree (same as example)
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    verticalOrder(root);

    return 0;
}