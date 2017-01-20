#include <stdio.h>


int LSearch(int arr[], int size, int target);
int BSearch(int arr[], int size, int target);

void main(void) {
	int arr1[100] = { 0 };
	int arr2[1000] = { 0 };
	int arr3[10000] = { 0 };

	int idx = 0;

	idx = LSearch(arr1, sizeof(arr1) / sizeof(int), 3);
	idx = LSearch(arr2, sizeof(arr2) / sizeof(int), 3);
	idx = LSearch(arr3, sizeof(arr3) / sizeof(int), 3);


	idx = BSearch(arr1, sizeof(arr1) / sizeof(int), 3);
	idx = BSearch(arr2, sizeof(arr2) / sizeof(int), 3);
	idx = BSearch(arr3, sizeof(arr3) / sizeof(int), 3);
}


int LSearch(int arr[], int size, int target) {
	int i = 0, opCount = 0;

	for (i = 0; i < size; i++) {
		if (arr[i] == target) {
			return i;
		}

		opCount++;
	}

	printf("순차탐색 : 사이즈가 %d일때, 연산횟수 %d\n", size, opCount);
	return -1;
}

int BSearch(int arr[], int size, int target) {
	int first = 0, last = size - 1, mid = 0;
	int opCount = 0;

	while (first <= last) {
		mid = (first + last) / 2;

		if (arr[mid] == target) {
			return mid;
		}
		else {
			if (arr[mid] > target) {
				last = mid - 1;
			}
			else {
				first = mid + 1;
			}
		}
		opCount++;
	}

	printf("이진탐색 : 사이즈가 %d일때, 연산횟수 %d\n", size, opCount);
	return -1;
}

