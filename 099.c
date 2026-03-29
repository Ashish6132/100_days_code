/* BST Insert

Implement the solution for this problem.
*/
#include <stdio.h>
#include <stdlib.h>

// Define structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert function
struct Node* insert(struct Node* root, int data) {
    // If tree is empty
    if (root == NULL) {
        return createNode(data);
    }

    // Insert in left subtree
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    // Insert in right subtree
    else {
        root->right = insert(root->right, data);
    }

    return root;
}

// Inorder traversal (to check BST)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder Traversal: ");
    inorder(root);

    return 0;
}