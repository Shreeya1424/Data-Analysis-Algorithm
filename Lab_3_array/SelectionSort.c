#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000  

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void printSampleArray(int arr[], int n) {
    printf("First 10 elements: ");
    for (int i = 0; i < 10 && i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    FILE *fp;
    int arr[N];
    int n = 0;
    clock_t start, end;
    double cpu_time_used;
    char worst_case[10000];

    printf("Enter input filename (e.g., input.txt): ");
    scanf("%s", "worst_case.txt");

    fp = fopen("worst_case.txt","r");
    if(fp == NULL) {
        printf("Error opening file '%s'.\n", "worst_case.txt");
        return 1;
    }

   
    while (fscanf(fp, "%d", &arr[n]) != EOF && n < N) {
        n++;
    }
    fclose(fp);

    printf("\nArray before sorting:\n");
    printSampleArray(arr, n);

    start = clock();

    selectionSort(arr, n);

    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    double time_ms = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;

    printf("\nArray after sorting:\n");
    printSampleArray(arr, n);

    printf("\nTime taken to sort %d elements: %.6f seconds (%.3f ms)\n", n, cpu_time_used, time_ms);

    return 0;
}
