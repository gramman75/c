#include <stdio.h>
#include "DBLinkedList.h"

void main(void)
{
	List plist;
	NData data;
	ListInit(&plist);
	LInsert(&plist, 1);
	LInsert(&plist, 2);
	LInsert(&plist, 3);
	LInsert(&plist, 4);
	LInsert(&plist, 5);
	LInsert(&plist, 6);

	if (LFirst(&plist, &data)) {
		printf("%d", data);

		while (LNext(&plist, &data)) {
			printf("%d", data);
		}

	}

	if (LFirst(&plist, &data)) {
		if (data % 2 == 0)
			LRemove(&plist);

		while (LNext(&plist, &data)) {
			if (data % 2 == 0)
				LRemove(&plist);
		}

	}

	putchar('\n');

	if (LFirst(&plist, &data)) {
		printf("%d", data);

		while (LNext(&plist, &data)) {
			printf("%d", data);
		}

	}
}