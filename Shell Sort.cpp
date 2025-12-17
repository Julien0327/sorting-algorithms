#include <stdio.h>
#define N 5

void shellSort(int a[], int n) {
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = a[i];
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap) {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
    }
}

int main() {
    int a[N] = {3, 5, 4, 2, 1};

    shellSort(a, N);

    for (int i = 0; i < N; i++)
        printf("%d,", a[i]);
    return 0;
}