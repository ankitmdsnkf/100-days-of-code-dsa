#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Helper function to create a new node
struct Node* createNode(int data) {
    if (data == -1) return NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build the tree from level-order array input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = createNode(arr[0]);
    struct Node* queue[n];
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    int i = 1;
    while (i < n && front < rear) {
        struct Node* current = queue[front++];
        if (current == NULL) continue;

        current->left = createNode(arr[i++]);
        if (current->left) queue[rear++] = current->left;
        
        if (i < n) {
            current->right = createNode(arr[i++]);
            if (current->right) queue[rear++] = current->right;
        }
    }
    return root;
}

// Function to mirror the tree
void mirror(struct Node* root) {
    if (root == NULL) return;

    // Swap the left and right pointers
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively mirror subtrees
    mirror(root->left);
    mirror(root->right);
}

// Function to print Inorder Traversal
void printInorder(struct Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root