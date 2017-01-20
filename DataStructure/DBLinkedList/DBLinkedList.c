#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List* plist) {
	plist->cur = NULL;
	plist->head = NULL;
	plist->numOfData = 0;
}


void LInsert(List* plist, LData data) {

	
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;	
	node->next = plist->head;
	
	
	if (plist->head != NULL)
		plist->head->prev = node;

	node->prev = NULL;
	plist->head = node;

	(plist->numOfData)++;
}

int LFirst(List* plist, LData* data) {
	if (plist->head == NULL)
		return FALSE;

	plist->cur = plist->head;
	*data = plist->cur->data;
}


int LNext(List* plist, LData* data) {
	if (plist->head == NULL || plist->cur->next == NULL)
		return FALSE;

	plist->cur = plist->cur->next;
	*data = plist->cur->data;

	return TRUE;
}

int LPrevious(List* plist, LData* data) {
	if (plist->head == NULL || plist->cur->prev == NULL)
		return FALSE;

	plist->cur = plist->cur->prev;
	*data = plist->cur->data;

	return TRUE;
}

int LCount(List* plist) {
	return plist->numOfData;
}
