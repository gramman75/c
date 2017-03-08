#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right) {

	int fidx, ridx, idx,i;
	int * tempArr;
	tempArr = (int*)malloc(sizeof(int) * (right + 1));
	fidx = left;
	ridx = mid + 1;
	idx = left;
	

	while (fidx <= mid && ridx <= right) {
		if (arr[fidx] > arr[ridx])
			tempArr[idx] = arr[ridx++];
		else
			tempArr[idx] = arr[fidx++];

		idx++;
	}

	if (fidx > mid) {
		for (i = ridx; i <= right; i++) {
			tempArr[idx++] = arr[i];
		}
	}

	if (ridx > right) {
		for (i = fidx; i <= mid; i++) {
			tempArr[idx++] = arr[i];
		}
	}

	for (i = left; i <= right; i++) {
		arr[i] = tempArr[i];
	}
}

void MergeSort(int arr[], int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		MergeSort(arr, 0, mid);
		MergeSort(arr, mid + 1, right);

		MergeTwoArea(arr, left, mid, right);
	}
}

void main(void) {
	int arr[5] = { 1, 6, 3, 7, 2 };

	MergeSort(arr, 0, (sizeof(arr) / sizeof(int))-1);

	for (int i = 0; i <(sizeof(arr) / sizeof(int)); i++)
		printf("%d", arr[i]);
}