#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

void insertionSort(int arr[], int n) {
    int i, key, j;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[N];
    clock_t start, end;
    double time_taken;

    for (int i = 0; i < N; i++)
        arr[i] = rand() % 1000;

    printf("Original array:\n");
    printArray(arr, N);

    start = clock();

    insertionSort(arr, N);

    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nSorted array:\n");
    printArray(arr, N);

    printf("\nTime taken to sort %d elements: %f seconds\n", N, time_taken);

    return 0;
}
