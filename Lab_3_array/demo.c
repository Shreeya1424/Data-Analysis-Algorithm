#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 50000  

void bubbleSort(int arr[], int n) {
    int i, j, temp, swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
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

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void generateBestCase(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = i;
}

void generateWorstCase(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = n - i;
}

void generateAverageCase(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000;
}

void printSampleArray(int arr[], int n) {
    printf("First 10 elements: ");
    for (int i = 0; i < 10 && i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int *arr = (int *)malloc(N * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int caseChoice, sortChoice;
    clock_t start, end;
    double cpu_time_used;

    printf("Choose Input Case:\n");
    printf("1. Best Case\n");
    printf("2. Worst Case\n");
    printf("3. Average Case\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &caseChoice);

    switch (caseChoice) {
        case 1:
            generateBestCase(arr, N);
            break;
        case 2:
            generateWorstCase(arr, N);
            break;
        case 3:
        default:
            generateAverageCase(arr, N);
            break;
    }

    printf("\nArray Sample Before Sorting:\n");
    printSampleArray(arr, N);

    printf("\nChoose Sorting Algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Heap Sort\n");
    printf("Enter your choice (1-2): ");
    scanf("%d", &sortChoice);

    start = clock();

    switch (sortChoice) {
        case 1:
            bubbleSort(arr, N);
            break;
        case 2:
            heapSort(arr, N);
            break;
        default:
            printf("Invalid sorting choice.\n");
            free(arr);
            return 1;
    }

    end = clock();

    cpu_time_used  = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nSorted Array Sample:\n");
    printSampleArray(arr, N);
    printf("\nTime taken to sort %d elements: %.4f seconds\n", N, cpu_time_used);

    free(arr);
    return 0;  
}
