#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to count leaf nodes
int countLeafNodes(struct Node* root) {
    // Base case: empty tree
    if (root == NULL) {
        return 0;
    }

    // If node is a leaf, return 1
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    // Total leaves = leaves in left subtree + leaves in right subtree
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Total number of leaf nodes: %d\n", countLeafNodes(root));

    return 0;
}