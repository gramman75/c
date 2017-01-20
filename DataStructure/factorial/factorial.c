#include <stdio.h>

int Factorial(int num) {

	if (num == 1)
		return num;

	return num * Factorial(num-1);

}

void main(void) {
	printf("%d\n", Factorial(9));
}