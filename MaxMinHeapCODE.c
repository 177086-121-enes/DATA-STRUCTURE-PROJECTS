#include <stdio.h>

void heapifyUp(int heap[], int index) {
    int parent;
    while (index > 0) {
        parent = (index - 1) / 2;
        if (heap[parent] < heap[index]) {
            int temp = heap[parent];
            heap[parent] = heap[index];
            heap[index] = temp;
            index = parent;
        } else break;
    }
}

int main() {
    int heap[10], size = 0;
    int i, n = 5, val[] = {10, 20, 5, 30, 15};

    for (i = 0; i < n; i++) {
        heap[size] = val[i];
        heapifyUp(heap, size);
        size++;
    }

    printf("Max Heap: ");
    for (i = 0; i < size; i++)
        printf("%d ", heap[i]);

    return 0;
}

