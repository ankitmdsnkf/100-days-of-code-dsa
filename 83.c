#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Assume the current index is the minimum
        int minIdx = i;

        // Find the actual minimum element in the remaining unsorted array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        // Swap the found minimum element with the element at index i
        if (minIdx != i) {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

int main() {
    int n;
    
    // Read the size of the array
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    
    // Read n integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform Selection Sort
    selectionSort(arr, n);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");

    return 0;
}