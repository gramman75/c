#include <stdio.h>
#include "SimpleHeap.h"

int GetParentIdx(int idx) {
	return idx / 2;
}

int GetLChildIdx(int idx) {
	return idx * 2;
}

int GetRChildIdx(int idx) {
	return idx * 2 + 1;
}

int GetHiPriChildIdx(Heap *ph, int idx) {
	if (GetLChildIdx(idx) > ph->numOfData) {
		return 0;
	}
	else if (GetLChildIdx(idx) == ph->numOfData) {
		return GetLChildIdx(idx);
	}
	else {
		if ((ph->heapArr[GetLChildIdx(idx)].pr) > (ph->heapArr[GetRChildIdx(idx)].pr)) {
			return GetRChildIdx(idx);
		}
		else {
			return GetLChildIdx(idx);
		}
	}
}

void HeapInit(Heap *ph) {
	ph->heapArr;
	ph->numOfData = 0;
}



int HIsEmpty(Heap *ph) {
	if (ph->numOfData == 0)
		return FALSE;
	else
		return TRUE;
}
void HInsert(Heap *ph, HData data, Priority pr) {
	int idx = ph->numOfData + 1;
	HeapElem newElem;
	newElem.data = data;
	newElem.pr = pr;

	while (idx != 1) {
		if (ph->heapArr[GetParentIdx(idx)].pr > pr) {
			ph->heapArr[idx] = ph->heapArr[GetParentIdx(idx)];
			idx = GetParentIdx(idx);
		}
		else {
			break;
		}
	}

	ph->numOfData += 1;
	ph->heapArr[idx] = newElem;

}
HData HDelete(Heap *ph) {
	int idx = 1, childIdx;
	HeapElem topElem = ph->heapArr[1];
	HeapElem bottomElem = ph->heapArr[ph->numOfData];

	ph->heapArr[1] = ph->heapArr[ph->numOfData];

	while (childIdx = GetHiPriChildIdx(ph, idx)){
		if (bottomElem.pr > ph->heapArr[childIdx].pr) {
			ph->heapArr[idx] = ph->heapArr[childIdx];
			idx = childIdx;
		}
		else {
			break;
		}
	}

	ph->numOfData -= 1;
	ph->heapArr[idx] = bottomElem;

	return topElem.data;
}