#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

int comp(LData d1, LData d2) {
	if (d1 > d2)
		return 1;
	else
		return 0;
}

void main(void) {
	LData data = 1;

	List list;
	ListInit(&list);
	setSortRole(&list, comp);

	while (1)
	{
		
		printf("Number : ");
		scanf("%d", &data);
		if (data <= 0)
			break;

		LInsert(&list, data);
		
	}

	printf("Count : %d\n", LCount(&list));
	//putchar('\n');

	printf("Data출력\n");

	if (LFirst(&list, &data)) {
		printf("%d\n", data);

		while (LNext(&list, &data)) {
			printf("%d\n", data);
		}
	}

	// Remove

	if (LFirst(&list, &data)) {
		if (data == 2) {
			LRemove(&list);
		}

		while (LNext(&list, &data)) {
			if (data == 2) {
				LRemove(&list);
			}
		}		
	}

	printf("After Count : %d", LCount(&list));

	printf("Data출력\n");

	if (LFirst(&list, &data)) {
		printf("%d\n", data);

		while (LNext(&list, &data)) {
			printf("%d\n", data);
		}
	}

}