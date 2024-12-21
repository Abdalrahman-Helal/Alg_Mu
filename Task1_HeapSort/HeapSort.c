#include <stdio.h>

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i;            // Initialize largest as root
    int left = 2 * i + 1;       // left = 2*i + 1
    int right = 2 * i + 2;      // right = 2*i + 2

    // See if left child of root exists and is greater than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // See if right child of root exists and is greater than root
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Change root, if needed
    if (largest != i) {
        // Swap arr[i] and arr[largest]
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to perform heapsort
void heapsort(int arr[], int n) {
    // Build a max heap (Rearrange the array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // One by one extract elements from the heap
    for (int i = n - 1; i > 0; i--) {
        // Swap the root (max) element with the last element
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to test the heapsort
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    printArray(arr, n);

    heapsort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}