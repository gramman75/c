#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "Point.h"

void main(void) {
	List list;
	Point* pos;
	LData data;

	ListInit(&list);

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