//Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

//Input Format:
//- First line contains integer N
//- Second line contains level-order traversal (-1 represents NULL)
//- Third line contains two node values

//output Format:
//- Print the LCA value

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

// LCA function
struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    struct Node* left = findLCA(root->left, n1, n2);
    struct Node* right = findLCA(root->right, n1, n2);

    if (left && right) return root;

    return left ? left : right;
}

int main() {
    // manually creating tree
    struct Node* root = newNode(3);
    root->left = newNode(5);
    root->right = newNode(1);
    root->left->left = newNode(6);
    root->left->right = newNode(2);
    root->right->left = newNode(0);
    root->right->right = newNode(8);

    struct Node* lca = findLCA(root, 5, 1);

    printf("LCA = %d\n", lca->data);

    return 0;
}