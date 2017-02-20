#include <stdio.h>
#include "Deque.h"

void main(void) {
	Deque dq;
	DqueueInit(&dq);

	DQAddFirst(&dq, 1);
	DQAddFirst(&dq, 2);
	DQAddFirst(&dq, 3);
	DQAddFirst(&dq, 4);
	DQAddFirst(&dq, 5);

	while (!DQIsEmpty(&dq))
	{
		printf("%d\n", DQRemoveFirst(&dq));
	}
}