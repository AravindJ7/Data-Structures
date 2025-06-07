#include <stdio.h>

void QUICK_SORT(int A[10], int first, int last) {
    int pivot, i, j, temp;

    if (first < last) {
        pivot = first;
        i = first;
        j = last;

        while (i < j) {
            while ((A[i] <= A[pivot]) && (i < last)) {
                i++;
            }
            while (A[j] > A[pivot]) {
                j--;
            }
            if (i < j) {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }

        // Place pivot at the correct position
        temp = A[pivot];
        A[pivot] = A[j];
        A[j] = temp;

        // Recursive calls
        QUICK_SORT(A, first, j - 1);
        QUICK_SORT(A, j + 1, last);
    }
}

void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int A[10] = {9, 5, 1, 4, 3, 7, 2, 6, 8, 0};
    int size = 10;

    printf("Original array:\n");
    printArray(A, size);

    QUICK_SORT(A, 0, size - 1);

    printf("Sorted array:\n");
    printArray(A, size);

    return 0;
}
