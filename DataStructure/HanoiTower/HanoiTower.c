#include <stdio.h>
#include <time.h>

void HanoiTowerMove(int num, char from, char by, char to);

int count = 0;

void main(void) {
	float gap;
	time_t startTime = 0, endTime = 0;
	startTime = clock();

	HanoiTowerMove(20, 'A', 'B', 'C');

	printf("%d\n", count);
	endTime = clock();
	gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC);
	printf("Elapse Time : %f second\n", gap);
}


void HanoiTowerMove(int num, char from, char by, char to){
	if (num == 1) {
		count++;
		//printf("���� 1�� %c���� %c�� �̵�\n", from, to);
	}
	else {
		HanoiTowerMove(num-1, from, to, by);
		//printf("���� %d�� %c���� %c�� �̵�\n",num, from, to);
		count++;
		HanoiTowerMove(num-1, by, from, to);
	}
}