/*Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO
*/
#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Create new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Count nodes
int countNodes(struct node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check Complete Binary Tree
int isCBT(struct node* root, int index, int total) {
    if (root == NULL)
        return 1;

    if (index >= total)
        return 0;

    return isCBT(root->left, 2 * index + 1, total) &&
           isCBT(root->right, 2 * index + 2, total);
}

// Check Min Heap property
int isMinHeap(struct node* root) {
    // Leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Only left child
    if (root->right == NULL) {
        return (root->data <= root->left->data) &&
               isMinHeap(root->left);
    }

    // Both children
    if (root->data <= root->left->data &&
        root->data <= root->right->data) {
        return isMinHeap(root->left) &&
               isMinHeap(root->right);
    }

    return 0;
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter level-order traversal:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Create nodes array
    struct node* nodes[n];

    for (int i = 0; i < n; i++) {
        nodes[i] = createNode(arr[i]);
    }

    // Link nodes
    for (int i = 0; i < n; i++) {
        if (2 * i + 1 < n)
            nodes[i]->left = nodes[2 * i + 1];
        if (2 * i + 2 < n)
            nodes[i]->right = nodes[2 * i + 2];
    }

    struct node* root = nodes[0];

    int total = countNodes(root);

    if (isCBT(root, 0, total) && isMinHeap(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}