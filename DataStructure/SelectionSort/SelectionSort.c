#include <stdio.h>

void SelectionSort(int arr[], int size) {
	int i, j, maxIdx, temp;

	for (i = 0; i < size; i++) {
		maxIdx = i;
		for (j = i+1; j < size; j++) {
			if (arr[maxIdx] > arr[j]) {
				maxIdx = j;
			}
		}

		temp = arr[maxIdx];
		arr[maxIdx] = arr[i];
		arr[i] = temp;
	}
}

void main(void) {
	int arr[4] = { 4, 3,7,6 };

	SelectionSort(arr, 4);

	for (int i = 0; i < 4; i++) {
		printf("%d", arr[i]);
	}
}