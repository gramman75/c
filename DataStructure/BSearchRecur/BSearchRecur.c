#include <stdio.h>

int BSearchRecur(int arr[], int first, int last, int target);

void main(void) {
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int idx = -1;

	idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int), 4);

	printf("%d", idx);
}


int BSearchRecur(int arr[], int first, int last, int target) {
	int mid = 0;

	if (first > last) {
		return -1;
	}

	mid = (first + last) / 2;

	if (arr[mid] == target) {
		return mid;
	}
	else if (arr[mid] > target) {
		BSearchRecur(arr, first, mid - 1, target);
	}
	else {

		BSearchRecur(arr, mid+1, last, target);
	}

	
}
