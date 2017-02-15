#include <stdio.h>
#include "ListBaseQueue.h"

void main(void) {
	Queue pq;

	QueueInit(&pq);

	Enqueue(&pq, 1);
	Enqueue(&pq, 2);
	Enqueue(&pq, 3);
	Enqueue(&pq, 4);
	Enqueue(&pq, 5);

	while (!QisEmpty(&pq))
	{
		printf("%d\n", Dequeue(&pq));
	}

}