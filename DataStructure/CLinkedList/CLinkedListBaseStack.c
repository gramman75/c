#include <stdio.h>
#include "CLinkedList.h"
#include "CLinkedListBaseStack.h"

void StackInit(Stack *pstack) {
	ListInit(pstack);
}


int SIsEmpty(Stack *pstack) {
	if (LCount(pstack) == 0) {

		return TRUE;
	}
	else {

		return FALSE;
	}
}

void SPush(Stack *pstack, LData data) {
	LInsertFront(pstack, data);
}

LData SPop(Stack *pstack) {
	LData data;
	LFirst(pstack,&data);
	LRemove(pstack);
	return data;
}

LData SPeek(Stack *pstack) {
	return pstack->tail->next->data;
}