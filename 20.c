#include <stdio.h>

int main() {
    int n;
    // Read the size of the array
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    // Read n integers into the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;

    // Brute force approach: Check every possible subarray
    for (int i = 0; i < n; i++) {
        int current_sum = 0;
        for (int j = i; j < n; j++) {
            current_sum += arr[j];
            
            // If the sum of the current subarray [i...j] is zero
            if (current_sum == 0) {
                count++;
            }
        }
    }

    // Print the final count
    printf("%d\n", count);

    return 0;
}