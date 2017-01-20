#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

int WhoIsPrecede(Point* d1, Point* d2) {
	if (d1->xpos < d2->xpos) {
		return 0;
	}
	else if (d1->xpos == d2->xpos) {
		if (d1->ypos < d2->ypos) {
			return 0;
		}
		else {
			return 1;
		}
	}
	else {
		return 1;
	}

}

void main(void) {
	List list;
	Point* pos;
	LData data;

	ListInit(&list);
	setSortRole(&list, WhoIsPrecede);

	pos = (Point*)malloc(sizeof(Point));
	SetPointPos(pos, 2, 1);
	LInsert(&list, pos);


	pos = (Point*)malloc(sizeof(Point));
	SetPointPos(pos, 2, 2);
	LInsert(&list, pos);

	pos = (Point*)malloc(sizeof(Point));
	SetPointPos(pos, 3, 1);
	LInsert(&list, pos);

	pos = (Point*)malloc(sizeof(Point));
	SetPointPos(pos, 3, 1);
	LInsert(&list, pos);


	printf("Count : %d\n", list.numOfData);

	if (LFirst(&list, &data)) {
		ShowPointPos(data);

		while (LNext(&list, &data)) {
			ShowPointPos(data);
		}
	}





}