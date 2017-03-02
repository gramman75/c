#include <stdio.h>

void BubbleSort(int arr[], int size) {
	int i, j, temp;

	for (i = 0; i < size; i++) {
		for (j = i+1; j < size; j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void main(void) {
	int arr[4] = { 4, 5, 1, 3 };

	BubbleSort(arr, sizeof(arr) / sizeof(int));

	for (int i = 0; i < 4; i++) {
		printf("%d\t", arr[i]);
	}
}