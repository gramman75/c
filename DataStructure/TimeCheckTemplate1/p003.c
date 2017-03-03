#include <stdio.h>
#include <time.h>

int main(void) {
	float gap;
	time_t startTime = 0, endTime = 0;
	startTime = clock();

	// start code
	
	// end code

	endTime = clock();
	gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC);
	printf("Elapse Time : %f second\n", gap);

}