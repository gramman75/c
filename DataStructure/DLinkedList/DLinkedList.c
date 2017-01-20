#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List* plist) {
	//plist->head = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
	plist->comp = NULL;

	NODE* head = (NODE*)malloc(sizeof(NODE));
	head->next = NULL;
	plist->head = head;
}

void FInsert(List* plist, LData data) {
	NODE* node = (NODE*)malloc(sizeof(NODE));
	node->data = data;
	node->next = plist->head->next;
	plist->head->next = node;
	(plist->numOfData)++;
}

void SInsert(List* plist, LData data) {
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	NODE* pred = plist->head;
	newNode->data = data;

	while (pred->next != NULL && comp(data, pred->next->data) != 0) {
		pred = pred->next;
	}

	newNode->next = pred->next;
	pred->next = newNode;

	(plist->numOfData)++;
}

void LInsert(List* plist, LData data) {
	if (plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}


int LFirst(List* plist, LData* data) {
	if (plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head;	
	plist->cur = plist->head->next;

	*data = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, LData* data) {
	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*data = plist->cur->data;
	return TRUE;
}

LData LRemove(List* plist) {
	NODE* rData = plist->cur;
	LData data = rData->data;
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rData);
	(plist->numOfData)--;

	return data;
}

int LCount(List* plist) {
	return plist->numOfData;
}

void setSortRole(List* plist, int(*comp)(LData d1, LData d2)) {
	plist->comp = comp;
}