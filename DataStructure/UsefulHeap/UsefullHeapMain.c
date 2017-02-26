#include <stdio.h>
#include "UsefulHeap.h"

int CompFunc(HData d1, HData d2) {
	//return d1 - d2;
	return d2 - d1;
}

int main(void) {

	Heap heap;
	HeapInit(&heap, CompFunc);

	HInsert(&heap, 'd');
	HInsert(&heap, 'a');
	HInsert(&heap, 'e');
	HInsert(&heap, 'c');
	HInsert(&heap, 'b');

	while (!HIsEmpty(&heap))
	{
		printf("%c",HDelete(&heap));
	}
	return 0;
}