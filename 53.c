#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Helper structure for BFS queue
struct QueueNode {
    struct Node* node;
    int hd;
};

// Data structure to store all visited nodes for printing
struct NodeInfo {
    int data;
    int hd;
};

struct Node* createNode(int data) {
    if (data == -1) return NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void printVerticalOrder(struct Node* root, int n) {
    if (!root) return;

    struct QueueNode queue[100];
    struct NodeInfo nodes[100];
    int front = 0, rear = 0, nodeCount = 0;
    int minHD = 0, maxHD = 0;

    // Initialize BFS
    queue[rear++] = (struct QueueNode){root, 0};

    while (front < rear) {
        struct QueueNode current = queue[front++];
        struct Node* temp = current.node;
        int hd = current.hd;

        // Store node info
        nodes[nodeCount++] = (struct NodeInfo){temp->data, hd};
        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (temp->left) 
            queue[rear++] = (struct QueueNode){temp->left, hd - 1};
        if (temp->right) 
            queue[rear++] = (struct QueueNode){temp->right, hd + 1};
    }

    // Print column by column
    for (int i = minHD; i <= maxHD; i++) {
        int first = 1;
        for (int j = 0; j < nodeCount; j++) {
            if (nodes[j].hd == i) {
                if (!first) printf(" ");
                printf("%d", nodes[j].data);
                first = 0;
            }
        }
        printf("\n");
    }
}

// Level-order construction
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = createNode(arr[0]);
    struct Node* q[100];
    int f = 0, r = 0;
    q[r++] = root;
    int i = 1;
    while (i < n) {
        struct Node* curr = q[f++];
        if (i < n) {
            curr->left = createNode(arr[i++]);
            if (curr->left) q[r++] = curr->left;
        }
        if (i < n) {
            curr->right = createNode(arr[i++]);
            if (curr->right) q[r++] = curr->right;
        }
    }
    return root;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[100];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    printVerticalOrder(root, n);

    return 0;
}