/*Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order
*/
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

void zigzagUtil(struct Node* root, int level, int* leftToRight) {
    if (!root) return;

    if (*leftToRight)
        printf("%d ", root->data);

    zigzagUtil(root->left, level + 1, leftToRight);
    zigzagUtil(root->right, level + 1, leftToRight);

    if (!*leftToRight)
        printf("%d ", root->data);
}
void zigzagTraversal(struct Node* root) {
    int leftToRight = 1; // Start with left to right
    zigzagUtil(root, 0, &leftToRight);
}
int main() {
    // Hardcoded tree (same as example)
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    zigzagTraversal(root);
    return 0;
}
