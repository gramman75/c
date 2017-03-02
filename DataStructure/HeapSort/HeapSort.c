#include <stdio.h>
#include "UsefulHeap.h"

int comp(HData d1, HData d2) {
	return d1 - d2;
}

void HeapSort(int arr[], int size, Comp comp) {
	Heap heap;

	HeapInit(&heap, comp);

	for (int i = 0; i < size; i++) {
		HInsert(&heap, arr[i]);
	}

	for (int i = 0; i < size; i++) {
		printf("%d",HDelete(&heap));
	}
}

void main(void) {
	int arr[] = { 7, 3, 9, 4 };

	HeapSort(arr, 4, comp);
}