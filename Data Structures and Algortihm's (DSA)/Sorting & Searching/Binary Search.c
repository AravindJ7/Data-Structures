#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;  // Found
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;  // Not found
}

// Main function
int main() {
    int arr[] = {1, 3, 4, 5, 9};  // Sorted array
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 4;

    int result = binarySearch(arr, size, key);

    if (result != -1)
        printf("Element %d found at index %d\n", key, result);
    else
        printf("Element %d not found\n", key);

    return 0;
}
