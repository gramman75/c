#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List* plist) {
	Node *headDummy, *tailDummy;
	headDummy = (Node*)malloc(sizeof(Node));
	tailDummy = (Node*)malloc(sizeof(Node));

	headDummy->next = tailDummy;
	headDummy->prev = NULL;

	tailDummy->prev = headDummy;
	tailDummy->next = NULL;

	plist->head = headDummy;
	plist->tail = tailDummy;
	plist->numOfData = 0;

}
void LInsert(List* plist, NData data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->tail;
	newNode->prev = plist->tail->prev;
	plist->tail->prev->next = newNode;

	plist->tail->prev = newNode;
	
	(plist->numOfData)++;
}

int LFirst(List* plist, NData* data) {
	if (plist->head->next == plist->tail)
		return FALSE;

	plist->cur = plist->head->next;
	*data = plist->cur->data;
	return TRUE;
}
int LNext(List* plist, NData* data) {
	if (plist->cur->next == plist->tail)
		return FALSE;

	plist->cur = plist->cur->next;
	*data = plist->cur->data;
	return TRUE;
}

NData LRemove(List* plist) {
	Node *removeNode = plist->cur;
	NData rtnData = removeNode->data;

	plist->cur->prev->next = plist->cur->next;
	plist->cur->next->prev = plist->cur->prev;

	plist->cur = plist->cur->prev;

	free(removeNode);
	(plist->numOfData)--;
	return rtnData;
}
int NCount(List* plist) {
	return plist->numOfData;
}