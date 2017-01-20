#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack *pstack) {
	pstack->head = NULL;
	pstack->numOfCount = 0;
}
int SIsEmpty(Stack *pstack) {
	if (pstack->head == NULL) {
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void SPush(Stack *pstack, NData data) {
	Node *newNode= (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = pstack->head;
	pstack->head = newNode;
}
NData SPop(Stack *pstack) {
	Node *dNode = pstack->head;
	NData data = dNode->data;

	if (SIsEmpty(pstack)) {
		printf("Stack is Empty");
		exit(-1);
	}

	pstack->head = pstack->head->next;
	free(dNode);
	return data;
}
NData SPeek(Stack *pstack) {
	NData data;

	if (SIsEmpty(pstack)) {
		printf("%s\n","Stack is Empty");
		exit(-1);
	}

	data = pstack->head->data;
	return data;
}