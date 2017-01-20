#include <stdio.h>
#include "ArrayList.h"

void removeCond(List *list, LData data) {
	if (((data % 2) == 0) || ((data % 3) == 0)) {
		LRemove(list);
	}
}
void main(void) {
	List list;
	int i = 0;
	LData data;

	// �ʱ�ȭ
	ListInit(&list);

	// 0 ~ 9���� Insert
	for (i = 0; i < 10; i++) {
		LInsert(&list, i);
	}

	// 2�� 3�� ��� ����
	if (LFirst(&list, &data)) {
		removeCond(&list, data);
	/*	if (((data % 2) == 0) || ((data % 3) == 0)) {
			LRemove(&list);
		}*/

		while (LNext(&list, &data)) {
			removeCond(&list, data);
		/*	if (((data % 2) == 0) || ((data % 3) == 0)) {
				LRemove(&list);
			}*/
		}
	}

	// Data���
	for (i = 0; i < list.numOfData; i++) {
		printf("%d\t", list.arr[i]);
	}

	putchar('\n');
}