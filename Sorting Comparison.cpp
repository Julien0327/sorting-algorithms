#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000   // Data size, adjustable

/************** Utility functions **************/
void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

//Basic Sort: Bubble Sort
void bubbleSort(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

//Quick Sort
int partition(int a[], int low, int high) {
    int pivot = a[low];
    while (low < high) {
        while (low < high && a[high] >= pivot)
            high--;
        a[low] = a[high];
        while (low < high && a[low] <= pivot)
            low++;
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

//Shell Sort
void shellSort(int a[], int n) {
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = a[i];
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];
            a[j] = temp;
        }
    }
}

//Heap Sort
void heapAdjust(int a[], int i, int n) {
    int temp = a[i];
    int child;
    for (; 2 * i + 1 < n; i = child) {
        child = 2 * i + 1;
        if (child + 1 < n && a[child] < a[child + 1])
            child++;
        if (temp >= a[child])
            break;
        a[i] = a[child];
    }
    a[i] = temp;
}

void heapSort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapAdjust(a, i, n);
    for (int i = n - 1; i > 0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapAdjust(a, 0, i);
    }
}

int main() {
    int origin[N];
    int temp[N];
    clock_t start, end;

    // Generate random data
    srand((unsigned)time(NULL));
    for (int i = 0; i < N; i++)
        origin[i] = rand();

    //Bubble Sort 
    copyArray(origin, temp, N);
    start = clock();
    bubbleSort(temp, N);
    end = clock();
    printf("Bubble Sort Time: %.4f s\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    //Quick Sort
    copyArray(origin, temp, N);
    start = clock();
    quickSort(temp, 0, N - 1);
    end = clock();
    printf("Quick Sort Time:  %.4f s\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    //Shell Sort
    copyArray(origin, temp, N);
    start = clock();
    shellSort(temp, N);
    end = clock();
    printf("Shell Sort Time:  %.4f s\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    //Heap Sort
    copyArray(origin, temp, N);
    start = clock();
    heapSort(temp, N);
    end = clock();
    printf("Heap Sort Time:   %.4f s\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
