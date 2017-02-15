#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

#define ORDER_TIME	15

#define CHE_BUR	    0 
#define BUL_BUR	    1
#define DBL_BUR     2

#define CHE_BUR_TIME	    12
#define BUL_BUR_TIME	    15
#define DBL_BUR_TIME	    24


void main(void) {
	int cheCnt = 0, bulCnt = 0, dblCnt = 0;
	int order, makepro = 0;
	Queue pq;

	QueueInit(&pq);
	
	for (int sec = 0; sec <= 3600; sec++) {
		if (sec % ORDER_TIME == 0) {
			order = rand() % 3;

			switch (order)
			{
			case CHE_BUR:
				Enqueue(&pq, CHE_BUR_TIME);
				cheCnt++;
				break;
			case BUL_BUR:
				Enqueue(&pq, BUL_BUR_TIME);
				bulCnt++;
				break;
			case DBL_BUR:
				dblCnt++;
				Enqueue(&pq, DBL_BUR_TIME);
				break;
			}
		}

		if (makepro <= 0 && !QIsEmpty(&pq))
			makepro = Dequeue(&pq);

		makepro--;
	}

	printf("Cheese Burger Count : %d\n", cheCnt);
	printf("Bulgogi Burger Count : %d\n", bulCnt);
	printf("Double Burger Count : %d\n", dblCnt);
	printf("Space : %d\n", MAX_LEN);
}