#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue *pq) {
	pq->front = 0;
	pq->rear = 0;
}

int QIsEmpty(Queue *pq) {
	if (pq->front == pq->rear)
		return TRUE;
	else
		return FALSE;
}

int NextPosIdx(int pos) {
	if (pos == MAX_LEN - 1)
		return 0;
	else
		return pos + 1;
}

void Enqueue(Queue *pq, NData data) {
	if (NextPosIdx(pq->rear) == pq->front) {
		printf("Queue is full!");
		exit(-1);
	}
	
	pq->rear = NextPosIdx(pq->rear);
	pq->arr[pq->rear] = data;
};

NData Dequeue(Queue *pq) {
	if (QIsEmpty(pq)) {
		printf("Queue is empty!");
		exit(-1);
	}
	pq->front = NextPosIdx(pq->front);
	return pq->arr[pq->front];
}

NData QPeek(Queue *pq) {
	if (QIsEmpty(pq)) {
		printf("Queue is empty!");
		exit(-1);
	}
	return pq->arr[pq->front];
}