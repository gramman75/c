#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

void QueueInit(Queue *pq) {
	pq->front = NULL;
	pq->rear = NULL;
}

int QisEmpty(Queue *pq) {
	if (pq->front == NULL)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue *pq, NData data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if (QisEmpty(pq)) {
		pq->front = newNode;
		pq->rear = newNode;
	}
	else {
		pq->rear->next = newNode;
		pq->rear = newNode;
	}

}

NData Dequeue(Queue *pq) {
	Node * rmNode = NULL;
	NData data;

	if (QisEmpty(pq)) {
		printf("Queue is empty");
		exit(-1);
	};

	rmNode = pq->front;
	data = rmNode->data;
	pq->front = pq->front->next;

	free(rmNode);

	return data;
}

NData QPeek(Queue *pq) {

	if (QisEmpty(pq)) {
		printf("Queue is empty");
		exit(-1);
	};

	return pq->front->data;
}