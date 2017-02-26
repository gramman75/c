#include <stdio.h>
#include "SimpleHeap.h"

int main(void) {
	int i;
	Heap heap;
	HeapInit(&heap);

	HInsert(&heap, 'a', 1);
	HInsert(&heap, 'b', 3);
	HInsert(&heap, 'c', 5);
	HInsert(&heap, 'd', 2);
	HInsert(&heap, 'e', 4);

	for (i = 0; i < 5; i++) {
		printf("%c", HDelete(&heap));
	}
	return 0;
}