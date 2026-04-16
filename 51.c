#include <stdio.h>
#include <stdlib.h>

// Definition of the BST Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// Iterative function to find the LCA
struct Node* findLCA(struct Node* root, int n1, int n2) {
    while (root != NULL) {
        // If both n1 and n2 are smaller than root, LCA is in left
        if (n1 < root->data && n2 < root->data)
            root = root->left;
        
        // If both n1 and n2 are greater than root, LCA is in right
        else if (n1 > root->data && n2 > root->data)
            root = root->right;
        
        // We found the split point
        else
            return root;
    }
    return NULL;
}

int main() {
    int n, val, n1, n2;
    struct Node* root = NULL;

    // Input: Number of nodes
    if (scanf("%d", &n) != 1) return 0;

    // Input: Node values and build the BST
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    // Input: Two nodes to find LCA for
    scanf("%d %d", &n1, &n2);

    struct Node* lca = findLCA(root, n1, n2);

    if (lca != NULL)
        printf("%d\n", lca->data);

    return 0;
}