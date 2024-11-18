#include<stdio.h>
#include<stdlib.h>

#define MAX 20
int heap[MAX];
int heapSize = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }
    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void insert(int value) {
    int i;
    if (heapSize >= MAX) {
        printf("Heap is full\n");
    }
    heap[heapSize] = value;
    i = heapSize;
    heapSize++;

    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMin() {
    int min;
    if (heapSize <= 0) {
        printf("Heap is empty\n");
        return -1;
    }
    if (heapSize == 1) {
        heapSize--;
        return heap[0];
    }
    min = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;
    heapify(heap, heapSize, 0);
    return min;
}

void heapSort(int arr[], int n) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);  // Swap with the last unsorted element
        heapify(arr, i, 0);
    }
}

void increaseKey(int index, int newValue) {
    if (index < 0 || index >= heapSize) {
        printf("Invalid operation\n");
        return;
    }
    heap[index] = newValue;
    heapify(heap, heapSize, index);
}

void display() {
    for (int i = 0; i < heapSize; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

void main() {
    int i;
    insert(90);
    insert(40);
    insert(30);
    insert(20);
    printf("Initial elements in the list:\n");
    display();

    printf("Extracted element is %d\n", extractMin());
    printf("After extracting the minimum element, the heap -> ");
    display();

    printf("Performing successive operations\n");
    printf("Increasing key of index 1 to 35\n");
    increaseKey(1, 35);
    display();

    printf("Increasing key of index 0 to 50:\n");
    increaseKey(0, 50);
    display();

    printf("After performing heap sort:\n");
    int sortedHeap[MAX];
    int n = heapSize;

    for (int i = 0; i < n; i++) {
        sortedHeap[i] = heap[i];
    }

    heapSort(sortedHeap, n);

    printf("Sorted elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", sortedHeap[i]);
    }
    printf("\n");
}

void increaseKey(int index ,int newValue){
    while(index<0 || index>=heapSize){
        printf("Invalid index\n");return;
    }
    heap[index]=newValue;
}