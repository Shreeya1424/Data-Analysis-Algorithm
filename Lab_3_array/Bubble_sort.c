#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;

    for (i = 0; i < n - 1; i++) {
        swapped = 0; 

        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[N];
    int i;
    clock_t start, end;
    double cpu_time_used;

    for (i = 0; i < N; i++)
        arr[i] = rand() % 1000;  // values between 0 and 999

    printf("Original array:\n");
    printArray(arr, N);

    // Start timer
    start = clock();

    bubbleSort(arr, N);

    // Stop timer
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC  * 1000;

    printf("\nSorted array:\n");
    printArray(arr, N);

    printf("\nTime taken to sort %d elements: %f seconds\n", N, cpu_time_used);

    return 0;
}
