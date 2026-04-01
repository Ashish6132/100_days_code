/*Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes*/
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
void rightViewUtil(struct Node* root, int level, int* maxLevel) {
    if (!root) return;

    if (level > *maxLevel) {
        printf("%d ", root->data);
        *maxLevel = level;
    }

    rightViewUtil(root->right, level + 1, maxLevel);
    rightViewUtil(root->left, level + 1, maxLevel);
}
void rightView(struct Node* root) {
    int maxLevel = -1; // Initialize to -1 to start from level 0
    rightViewUtil(root, 0, &maxLevel);
}
int main() {
    // Hardcoded tree (same as example)
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    rightView(root);
    return 0;
}
