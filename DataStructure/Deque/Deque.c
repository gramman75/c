#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DqueueInit(Deque *dq) {
	dq->head= NULL;
	dq->tail= NULL;
}

int DQIsEmpty(Deque *dq) {
	if (dq->head== NULL)
		return TRUE;
	else
		return FALSE;
}

void DQAddFirst(Deque *dq, NData data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->prev = NULL;
	newNode->next = dq->head;
	
	if (DQIsEmpty(dq))
		dq->tail= newNode;
	else
		dq->head->prev = newNode;

	dq->head = newNode;
}
void DQAddLast(Deque *dq, NData data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->prev = dq->tail;
	newNode->next = NULL;

	if (DQIsEmpty(dq))
		dq->head = newNode;
	else
		dq->tail->next = newNode;

	dq->tail = newNode;
}

NData DQRemoveFirst(Deque *dq) {
	if (DQIsEmpty(dq)) {
		printf("Deque is empty!");
		exit(-1);
	}
	Node * rmNode = dq->head;
	NData rtnData = rmNode->data;

	dq->head = dq->head->next;

	free(rmNode);

	if (dq->head == NULL)
		dq->tail = NULL;
	else
		dq->head->prev = NULL;

	return rtnData;
}
NData DQRemoveLast(Deque *dq) {
	if (DQIsEmpty(dq)) {
		printf("Deque is empty!");
		exit(-1);
	}

	Node * rmNode = dq->tail;
	NData rtnData = rmNode->data;

	dq->tail = dq->tail->prev;

	free(rmNode);

	if (dq->tail == NULL)
		dq->head = NULL;
	else
		dq->tail->next = NULL;

	return rtnData;
}

NData DQGetFirst(Deque *dq) {
	if (DQIsEmpty(dq)) {
		printf("Deque is empty!");
		exit(-1);
	}
	return dq->head->data;
}
NData DQGetLast(Deque *dq) {
	if (DQIsEmpty(dq)) {
		printf("Deque is empty!");
		exit(-1);
	}

	return dq->tail->data;
}
