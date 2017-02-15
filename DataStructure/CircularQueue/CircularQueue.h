#pragma once
#ifndef __C_QUEUE__
#define __C_QUEUE__

#define TRUE	1
#define FALSE	0

#define MAX_LEN 35

typedef int	NData;

typedef struct _queue
{
	int front;
	int rear;
	NData arr[MAX_LEN];
} CQueue;

typedef CQueue Queue;

void QueueInit(Queue *pq);

int QIsEmpty(Queue *pq);

void Enqueue(Queue *pq, NData data);
NData Dequeue(Queue *pq);
NData QPeek(Queue *pq);




#endif // !__C_QUEUE__

