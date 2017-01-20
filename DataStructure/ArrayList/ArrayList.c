#include <stdio.h>
#include "ArrayList.h"


void ListInit(List * plist) {
	plist->curPosition = -1;
	plist->numOfData = 0;
}

void LInsert(List* plist, LData data) {
	if (plist->numOfData >= LIST_LEN) {
		printf("Can not insert data");
		return;
	}

	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

int LFirst(List* plist, LData* data) {
	if (plist->numOfData == 0) {
		return FASLE;
	}

	plist->curPosition = 0;
	*data = plist->arr[0];
	return TRUE;
}

int LNext(List* plist, LData* data) {
	if (plist->curPosition >= (plist->numOfData)-1)
		return FASLE;

	(plist->curPosition)++;
	*data = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List *plist) {
	int cpos = plist->curPosition, i = 0;
	int num = plist->numOfData;
	LData data = plist->arr[cpos];


	for (i = cpos; i < num - 1; i++) {
		plist->arr[i] = plist->arr[i + 1];
	}

	(plist->numOfData)--;
	(plist->curPosition)--;

	return data;
}


int LCount(List *plist) {
	return plist->numOfData;
}