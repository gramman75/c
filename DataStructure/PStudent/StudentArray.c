#include <stdio.h>
#include <stdlib.h>

void AverageSubject(int **arr,int students, int subjects) {
	int avg = 0, sum=0;
	for (int i = 0; i < students; i++) {
		printf("학생 %d 평균:", i);
		for (int j = 0; j < subjects; j++) {
			sum = sum + arr[i][j];
		}
		printf("%3d\n", sum / subjects);
	}
}

void main(void) {
	int students, subjects, point;

	int **arr;

	printf("학생수:");
	scanf_s("%d", &students);	

	printf("과목수:");
	scanf_s("%d", &subjects);

	arr = (int**)malloc(sizeof(int*) * students);

	for (int i = 0; i < students; i++) {
		arr[i] = (int*)malloc(sizeof(int) * subjects);
	}

	for (int m = 0; m < students; m++) {
		printf("학생 %d----------\n", m);
		for (int n = 0; n < subjects; n++) {
			printf("과목 %d 점수 :", n);
			scanf_s("%d", &point);

			arr[m][n] = point;
		}
	}

	printf("-------출력---------\n");

	for (int m = 0; m < students; m++) {
		printf("학생 %d----------\n", m);
		for (int n = 0; n < subjects; n++) {
			printf("과목 %d 점수 : %d\n",n, arr[m][n]);
		}
	}
	AverageSubject(arr, students, subjects);
	for (int i = 0; i < students; i++) {
		free(arr[i]);
	}
	free(arr);
}