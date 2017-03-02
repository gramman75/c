#include <stdio.h>

void InsertionSort(int arr[], int size) {
	int target, i, j;

	for (i = 1; i < size; i++) {
		target = arr[i];
		for(j =i-1; j >= 0; j--) {
			if (arr[j] > target) {
				arr[j+1] = arr[j];
			}
			else {
				break;
			}
		}

		arr[j + 1] = target;
	}
}

void main(void) {
	int arr[] = { 5, 3, 6 ,1 };
	InsertionSort(arr, 4);

	for (int i = 0; i < 4; i++) {
		printf("%d", arr[i]);
	}
}

