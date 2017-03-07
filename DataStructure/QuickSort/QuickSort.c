#include <stdio.h>

void Swap(int arr[], int idx1, int idx2) {
	int temp;
	temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int Partition(int arr[], int left, int right) {
	int low = left+1, high = right;
	int pivot = left;

	while (low <= high) {
		while (arr[pivot] > arr[low])
			low++;

		while (arr[pivot] < arr[high])
			high--;

		if (low <= high)
			Swap(arr, low, high);
	}

	Swap(arr, pivot, high);

	return high;

}

void QuickSort(int arr[], int left, int right) {
	int pivot;

	if (left < right) {
		pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}

void main(void) {
	int arr[9] = { 5,1,3,7,9,2,4,6,8 };

	QuickSort(arr, 0, 8);

	for (int i = 0; i < 9; i++) {
		printf("%d", arr[i]);
	}


}

