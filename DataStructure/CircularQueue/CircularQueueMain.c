#include <stdio.h>
#include "CircularQueue.h"

void main(void) {
	Queue q;

	QueueInit(&q);
	Enqueue(&q, 1);
	Enqueue(&q, 2);
	Enqueue(&q, 3);
	Enqueue(&q, 4);
	Enqueue(&q, 5);
	

	while (!QIsEmpty(&q))
	{
		printf("%d\n", Dequeue(&q));
	}
}
