#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Copy the remaining elements
    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Input case generators
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

// File I/O
void writeArrayToFile(int arr[], int n, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", arr[i]);
    }
    fclose(fp);
}

void readArrayFromFile(int arr[], int n, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);
}

void printSampleArray(int arr[], int n) {
    printf("First 10 elements: ");
    for (int i = 0; i < 10 && i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int *arr = (int *)malloc(N * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int choice;
    char filename[30];
    clock_t start, end;
    double cpu_time_used;

    printf("Choose Input Case:\n");
    printf("1. Best Case (Already Sorted)\n");
    printf("2. Worst Case (Reverse Sorted)\n");
    printf("3. Average Case (Random Elements)\n");
    printf("4. Default Case (Random Elements)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            generateBestCase(arr, N);
            sprintf(filename, "best_case.txt");
            printf("\nBest Case Array:\n");
            break;
        case 2:
            generateWorstCase(arr, N);
            sprintf(filename, "worst_case.txt");
            printf("\nWorst Case Array:\n");
            break;
        case 3:
            generateAverageCase(arr, N);
            sprintf(filename, "average_case.txt");
            printf("\nAverage Case Array:\n");
            break;
        case 4:
        default:
            generateAverageCase(arr, N);
            sprintf(filename, "default_case.txt");
            printf("\nDefault Case Array:\n");
            break;
    }

    // Write and read from file
    writeArrayToFile(arr, N, filename);
    readArrayFromFile(arr, N, filename);

    // Print sample
    printSampleArray(arr, N);

    // Start sorting using Merge Sort
    start = clock();
    mergeSort(arr, 0, N - 1);
    end = clock();

    // Timing in seconds
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Output
    printf("\nSorted Array Sample:\n");
    printSampleArray(arr, N);
    printf("\nTime taken to sort %d elements using Merge Sort: %.4f seconds\n", N, cpu_time_used);

    // Cleanup
    free(arr);
    return 0;
}
