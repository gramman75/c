#include <stdio.h>
#include "ArrayList.h"
#include "NameCard.h"

void main(void) {
	List plist;
	LData* data;

	ListInit(&plist);

	data = MakeNameCard("Kim", "010");
	LInsert(&plist, data);

	data = MakeNameCard("Lee", "020");
	LInsert(&plist, data);

	data = MakeNameCard("Park", "030");
	LInsert(&plist, data);

	data = MakeNameCard("Choi", "040");
	LInsert(&plist, data);

	printf("Count : %d\n", plist.numOfData);

	if (LFirst(&plist, &data)) {
		ShowNameCard(data);

		while (LNext(&plist, &data)) {
			ShowNameCard(data);
		}
	}
}