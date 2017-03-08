#include <stdio.h>
#include "ListBaseQueue.h"

#define BUCKET_NUM 10
void RadixSort(int arr[], int num, int maxLen) {
	Queue buckets[BUCKET_NUM];
	int rdx, digit = 1;

	for (int n = 0; n < BUCKET_NUM; n++) {
		QueueInit(&buckets[n]);
	}

	for (int i = 0; i < maxLen; i++) {
		for (int j = 0; j < num; j++) {
			rdx = arr[j] / digit % 10;

			Enqueue(&buckets[rdx], arr[j]);
		}

		for (int m = 0, idx=0; m < BUCKET_NUM; m++) {
			while(!QisEmpty(&buckets[m])) {
				arr[idx++] = Dequeue(&buckets[m]);
			}
		}

		digit *= 10;
	}
}
void main(void) {

	int arr[9] = { 32, 43, 95, 12, 54, 11, 24, 94, 39 };

	RadixSort(arr, 9, 2);

	for (int i = 0; i < 9; i++) {
		printf("%d\t", arr[i]);
	}

}