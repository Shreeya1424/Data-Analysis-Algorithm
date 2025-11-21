#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000000

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int binarysearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;  
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
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
    int target, result;

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

    writeArrayToFile(arr, N, filename);
    readArrayFromFile(arr, N, filename);

    printSampleArray(arr, N);

    printf("\nEnter target element to search: ");
    scanf("%d", &target);

    // Important: Sort the array if it's not already sorted
    if (choice != 1) {  // Best case is already sorted
        printf("\nSorting array before Binary Search...\n");
        start = clock();
        qsort(arr, N, sizeof(int), compare);
        end = clock();
        printf("Time taken for sorting: %.6f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    }

    start = clock();
    result = binarysearch(arr, N, target);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

    if (result != -1)
        printf("Element %d found at index %d\n", target, result);
    else
        printf("Element %d not found in the array.\n", target);

    printf("Time taken for binary search on %d elements: %.6f seconds\n", N, cpu_time_used);

    free(arr);
    return 0;
}
