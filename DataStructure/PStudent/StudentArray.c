#include <stdio.h>
#include <stdlib.h>

void main(void) {
	int students, subjects, point;

	int **arr;

	printf("�л���:");
	scanf_s("%d", &students);	

	printf("�����:");
	scanf_s("%d", &subjects);

	arr = (int**)malloc(sizeof(int*) * students);

	for (int i = 0; i < students; i++) {
		arr[i] = (int*)malloc(sizeof(int) * subjects);
	}

	for (int m = 0; m < students; m++) {
		printf("�л� %d----------\n", m);
		for (int n = 0; n < subjects; n++) {
			printf("���� %d ���� :", n);
			scanf_s("%d", &point);

			arr[m][n] = point;
		}
	}

	printf("-------���---------\n");

	for (int m = 0; m < students; m++) {
		printf("�л� %d----------\n", m);
		for (int n = 0; n < subjects; n++) {
			printf("���� %d ���� : %d\n",n, arr[m][n]);
		}
	}


	for (int i = 0; i < students; i++) {
		free(arr[i]);
	}

	free(arr);


}