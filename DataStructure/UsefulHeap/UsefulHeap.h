#pragma once
#ifndef __SIMPLE_HEAP_H
#define __SIMPLE_HEAP_H

#define FALSE	0
#define TRUE	1
#define HEAP_LEN 100

typedef char HData;
typedef int	Priority;
typedef int Comp(HData d1, HData d2);


//typedef struct _heapElem {
//	Priority pr;
//	HData data;
//} HeapElem;

typedef struct _heap {
	Comp *comp;
	int numOfData;
	HData heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap *ph, Comp *comp);
int HIsEmpty(Heap *ph);
void HInsert(Heap *ph, HData data);
HData HDelete(Heap *ph);

#endif // !__SIMPLE_HEAP_H

