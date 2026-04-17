#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    if (data == -1) return NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to build the tree from level-order array
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

void zigzagTraversal(struct Node* root) {
    if (!root) return;

    struct Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    bool leftToRight = true;

    while (front < rear) {
        int levelSize = rear - front;
        int levelData[levelSize];

        for (int i = 0; i < levelSize; i++) {
            struct Node* current = queue[front++];
            
            // Determine position based on direction
            int index = leftToRight ? i : (levelSize - 1 - i);
            levelData[index] = current->data;

            if (current->left) queue[rear++] = current->left;
            if (current->right) queue[rear++] = current->right;
        }

        for (int i = 0; i < levelSize; i++) {
            printf("%d ", levelData[i]);
        }
        
        leftToRight = !leftToRight; // Flip direction for next level
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);
    zigzagTraversal(root);
    printf("\n");

    return 0;
}