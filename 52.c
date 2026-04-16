#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    if (data == -1) return NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Level-order construction of the tree
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = createNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;
    while (i < n) {
        struct Node* current = queue[front++];
        if (i < n) {
            current->left = createNode(arr[i++]);
            if (current->left) queue[rear++] = current->left;
        }
        if (i < n) {
            current->right = createNode(arr[i++]);
            if (current->right) queue[rear++] = current->right;
        }
    }
    return root;
}

// Function to find LCA in a Binary Tree
struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL || root->data == n1 || root->data == n2) {
        return root;
    }

    struct Node* left = findLCA(root->left, n1, n2);
    struct Node* right = findLCA(root->right, n1, n2);

    // If both left and right are non-NULL, current node is LCA
    if (left != NULL && right != NULL) {
        return root;
    }

    // Otherwise, return the non-NULL child
    return (left != NULL) ? left : right;
}

int main() {
    int n, n1, n2;
    if (scanf("%d", &n) != 1) return 0;

    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d %d", &n1, &n2);

    struct Node* root = buildTree(arr, n);
    struct Node* lca = findLCA(root, n1, n2);

    if (lca) printf("%d\n", lca->data);

    return 0;
}