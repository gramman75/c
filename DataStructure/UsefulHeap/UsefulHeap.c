#include <stdio.h>
#include "UsefulHeap.h"

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
		//if ((ph->heapArr[GetLChildIdx(idx)].pr) > (ph->heapArr[GetRChildIdx(idx)].pr)) {
		if (ph->comp(ph->heapArr[GetLChildIdx(idx)], ph->heapArr[GetRChildIdx(idx)]) > 0 ){
			return GetRChildIdx(idx);
		}
		else {
			return GetLChildIdx(idx);
		}
	}
}

void HeapInit(Heap *ph, Comp *comp) {
	ph->comp = comp;
	ph->heapArr;
	ph->numOfData = 0;
}



int HIsEmpty(Heap *ph) {
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}
void HInsert(Heap *ph, HData data) {
	int idx = ph->numOfData + 1;

	while (idx != 1) {
		//if (ph->heapArr[GetParentIdx(idx)].pr > pr) {
		if (ph->comp(ph->heapArr[GetParentIdx(idx)], data) > 0){
			ph->heapArr[idx] = ph->heapArr[GetParentIdx(idx)];
			idx = GetParentIdx(idx);
		}
		else {
			break;
		}
	}

	ph->numOfData += 1;
	ph->heapArr[idx] = data;

}
HData HDelete(Heap *ph) {
	int idx = 1, childIdx;
	HData topData = ph->heapArr[1];
	HData bottomData = ph->heapArr[ph->numOfData];
	ph->heapArr[1] = ph->heapArr[ph->numOfData];

	while (childIdx = GetHiPriChildIdx(ph, idx)) {
		//if (bottomElem.pr > ph->heapArr[childIdx].pr) {
		if(ph->comp(bottomData, ph->heapArr[childIdx]) > 0){
			ph->heapArr[idx] = ph->heapArr[childIdx];
			idx = childIdx;
		}
		else {
			break;
		}
	}

	ph->numOfData -= 1;
	ph->heapArr[idx] = bottomData;

	return topData;
}