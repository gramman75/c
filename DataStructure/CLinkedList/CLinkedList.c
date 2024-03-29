#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List* plist) {
	plist->before = NULL;
	plist->cur = NULL;
	plist->numOfData = 0;
	plist->tail = NULL;
}

void LInsert(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	

	if (plist->tail == NULL) {
		plist->tail = newNode;
		newNode->next = newNode;
		//plist->tail->next = newNode;
	}
	else {
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;
	}

	(plist->numOfData)++;
}

void LInsertFront(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;


	if (plist->tail == NULL) {
		plist->tail = newNode;
		newNode->next = newNode;
		//plist->tail->next = newNode;
	}
	else {
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}

	(plist->numOfData)++;
}

int LFirst(List* plist, LData* data) {
	plist->cur = plist->tail->next;
	plist->before = plist->tail;
	*data = plist->tail->next->data;
}

int LNext(List* plist, LData* data) {
	if (plist->tail == NULL)
		return FALSE;
	
	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*data = plist->cur->data;

	return TRUE;
}


LData LRemove(List* plist) {
	Node* rNode = plist->cur;
	LData data = rNode->data;

	if (rNode == plist->tail) {
		if (plist->tail = plist->tail->next) {
			plist->tail = NULL;
		}
		else {
			plist->tail = plist->before;
		}
	}

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;
	free(rNode);
	(plist->numOfData)--;

	return data;
}

int LCount(List* plist) {
	return plist->numOfData;
}