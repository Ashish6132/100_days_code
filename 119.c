/*Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree
*/

#include <stdio.h>
#include <stdlib.h>

// Tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Find index in inorder
int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree
struct Node* buildTree(int inorder[], int postorder[], int* postIndex, int start, int end) {
    if (start > end)
        return NULL;

    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct Node* root = newNode(rootVal);

    if (start == end)
        return root;

    int inIndex = findIndex(inorder, start, end, rootVal);

    // IMPORTANT: right first
    root->right = buildTree(inorder, postorder, postIndex, inIndex + 1, end);
    root->left  = buildTree(inorder, postorder, postIndex, start, inIndex - 1);

    return root;
}

// Preorder traversal
void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    // fixed size (safe for all compilers)
    int inorder[100], postorder[100];

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, &postIndex, 0, n - 1);

    preorder(root);

    return 0;
}