#include <stdio.h>

int Fibo(int num) {
	if (num == 1) {
		return 0;
	}
	else if (num == 2) {
		return 1;
	}
	else {
		return Fibo(num - 1) + Fibo(num - 2);
	}
}
void main(void) {
	int i;

	for (i = 1; i < 15; i++) {
		printf("%d  ", Fibo(i));
	}

	putchar('\n');
	

}