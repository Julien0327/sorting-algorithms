#include<stdio.h>

typedef struct {
    int *data;
    int size;
}MaxHeap;

void ShiftDown(MaxHeap* heap, int index){
    while (1)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        //Find the largest among index, left and right
        if (left < heap->size && heap->data[left] > heap->data[largest]) {
            largest = left;
        }
        if (right < heap->size && heap->data[right] > heap->data[largest]) {
            largest = right;
        }

        //If largest is not index, swap and continue downwards
        if (largest != index) {
            int temp = heap->data[index];
            heap->data[index] = heap->data[largest];
            heap->data[largest] = temp;

            index = largest;
        } else break;
    }
}

void BuildMaxHeap(MaxHeap* heap){
    for (int i = (heap->size / 2) - 1; i >= 0; i--)
        ShiftDown(heap, i);
}

void HeapSort(MaxHeap *heap){
    int originalSize = heap->size;
    //Build max heap
    BuildMaxHeap(heap);
    for (int i = heap->size-1; i > 0; i--)
    {
        //Swap the root(maximum) with the last element
        int temp = heap->data[0];
        heap->data[0] = heap->data[i];
        heap->data[i] = temp;

        heap->size--;  //Reduce the size of heap as last element is in its correct position

        //Heapify the root element to get the highest element at root again
        ShiftDown(heap, 0);
    }
    heap->size = originalSize; //Restore original size
}

void PrintHeap(MaxHeap* heap) {
    printf("Max Heap elements: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {3, 5, 1, 10, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    MaxHeap heap = {arr, n};

    printf("Before building max heap:\n");
    PrintHeap(&heap);

    BuildMaxHeap(&heap);
    printf("\nAfter building max heap:\n");
    PrintHeap(&heap);

    HeapSort(&heap);
    printf("\nAfter heap sort:\n");
    PrintHeap(&heap);

    return 0;
}