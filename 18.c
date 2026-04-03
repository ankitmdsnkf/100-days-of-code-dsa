#include <stdio.h>

// Helper function to reverse a portion of the array
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n, k;
    if (scanf("%d", &n) != 1) return 0;
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    if (scanf("%d", &k) != 1) return 0;

    k = k % n;

    reverse(arr, 0, n - k - 1);
    reverse(arr, n - k, n - 1);
  
    reverse(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");

    return 0;
}