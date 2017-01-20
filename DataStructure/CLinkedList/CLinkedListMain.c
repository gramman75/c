#include <stdio.h>
#include "CLinkedList.h"

void main(void) {
	List plist;
	LData data;

	ListInit(&plist);

	LInsert(&plist, 1);
	LInsert(&plist, 2);
	LInsert(&plist, 3);
	LInsert(&plist, 4);
	LInsert(&plist, 5);
	LInsertFront(&plist, 10);

	if (LFirst(&plist, &data) != FALSE) {
		printf("%d\n", data);
		
		while (plist.cur != plist.tail) {
			if (LNext(&plist, &data) != FALSE) {
				printf("%d\n", data);
			}
		}
	}

	if (LFirst(&plist, &data) != FALSE) {
		if (data == 4) {
			LRemove(&plist);
		}

		while (plist.cur != plist.tail) {
			if (LNext(&plist, &data) != FALSE) {
				if (data == 4) {
					LRemove(&plist);
					break;
				}
			}
		}

		printf("Remove %d\n", data);
	}
	
	if (LFirst(&plist, &data) != FALSE) {
		printf("%d\n", data);

		while (plist.cur != plist.tail) {
			if (LNext(&plist, &data) != FALSE) {
				printf("%d\n", data);
			}
		}
	}



}