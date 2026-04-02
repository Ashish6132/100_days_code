/*Check whether a given binary tree is symmetric around its center.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print YES if symmetric, otherwise NO*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int data) {
    if (data == -1) return NULL;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Build tree (level order)
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = createNode(arr[0]);

    // queue (fixed size safe)
    struct Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct Node* curr = queue[front++];

        // left child
        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        // right child
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// Check mirror
bool isMirror(struct Node* a, struct Node* b) {
    if (a == NULL && b == NULL)
        return true;

    if (a == NULL || b == NULL)
        return false;

    return (a->data == b->data) &&
           isMirror(a->left, b->right) &&
           isMirror(a->right, b->left);
}

// Check symmetric
bool isSymmetric(struct Node* root) {
    if (root == NULL)
        return true;

    return isMirror(root->left, root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];   // FIX: avoid variable-length issues
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);   // FIX: no '&' mistake here
    }

    struct Node* root = buildTree(arr, n);

    if (isSymmetric(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}