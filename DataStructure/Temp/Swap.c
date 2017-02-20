#include <stdio.h>

void Swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void main(void) {
	int a = 1;
	int b = 2;

	Swap(&a, &b);

	printf("%d %d\n", a, b);

	printf("%d\n", '2' - '0');
}