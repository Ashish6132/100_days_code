/*Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int findIndex(int inorder[], int start, int end, int value) {
    int i;
    for (i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

struct Node* buildTree(int preorder[], int inorder[], int* preIndex, int start, int end) {
    if (start > end)
        return NULL;

    int rootVal = preorder[*preIndex];
    (*preIndex)++;

    struct Node* root = newNode(rootVal);

    if (start == end)
        return root;

    int inIndex = findIndex(inorder, start, end, rootVal);

    root->left = buildTree(preorder, inorder, preIndex, start, inIndex - 1);
    root->right = buildTree(preorder, inorder, preIndex, inIndex + 1, end);

    return root;
}

void postorder(struct Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n, i;

    scanf("%d", &n);

    // FIX: Use fixed size arrays
    int preorder[100], inorder[100];

    for (i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }

    for (i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    int preIndex = 0;

    struct Node* root = buildTree(preorder, inorder, &preIndex, 0, n - 1);

    postorder(root);

    return 0;
}