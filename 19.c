#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Fixed: Corrected the casting and dereferencing in the comparator
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    // Basic safety check for input
    if (scanf("%d", &n) != 1 || n < 2) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 1: Sort the array - O(n log n)
    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;
    int min_sum = INT_MAX;
    int res_l = 0, res_r = 0;

    // Step 2: Two-pointer approach
    while (left < right) {
        int sum = arr[left] + arr[right];

        // Check if current sum is closer to zero
        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            res_l = arr[left];
            res_r = arr[right];
        }

        if (sum == 0) break; // Found the absolute closest

        if (sum < 0) {
            left++;
        } else {
            right--;
        }
    }

    // Output result
    printf("%d %d\n", res_l, res_r);

    return 0;
}