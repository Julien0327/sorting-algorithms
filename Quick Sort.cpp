#include <stdio.h>
#define N 5

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
        int pivotPos = partition(a, low, high);
        quickSort(a, low, pivotPos - 1);
        quickSort(a, pivotPos + 1, high);
    }
}

int main() {
    int a[N] = {3, 5, 4, 2, 1};

    quickSort(a, 0, N - 1);

    for (int i = 0; i < N; i++)
        printf("%d,", a[i]);
    return 0;
}