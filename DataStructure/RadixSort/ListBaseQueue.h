#pragma once
#ifndef __LIST_BAES_QUEUE
#define __LIST_BASE_QUEUE

#define TRUE	1
#define FALSE	0

typedef int NData;

typedef struct _node {
	NData data;
	struct _node * next;
} Node;

typedef struct _lQueue {
	Node * front;
	Node * rear;
} LQueue;

typedef LQueue Queue;

void QueueInit(Queue *pq);
int  QisEmpty(Queue *pq);
void Enqueue(Queue *pq, NData data);
NData Dequeue(Queue *pq);
NData QPeek(Queue *pq);



#endif // !__LIST_BAES_QUEUE

