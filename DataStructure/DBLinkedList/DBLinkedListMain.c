#include <stdio.h>
#include "DBLinkedList.h"

void main(void) {
	List plist;
	ListInit(&plist);

	LData data;
	LInsert(&plist, 1);
	LInsert(&plist, 2);
	LInsert(&plist, 3);
	LInsert(&plist, 4);
	LInsert(&plist, 5);

	if (LFirst(&plist, &data) != FALSE) {
		printf("%d\n",data);

		while (LNext(&plist, &data) != FALSE) {
			printf("%d\n", data);
		}
		
		while (LPrevious(&plist, &data) != FALSE) {
			printf("%d\n", data);
		}
	}

}