#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack *stack) {
	stack->topOfIndex = -1;
}

int SIsEmpty(Stack *statck) {
	if (statck->topOfIndex == -1)
		return TRUE;
	else
		return FALSE;
}
void SPush(Stack *stack, NData data) {
	
	stack->topOfIndex +=1;
	stack->data[stack->topOfIndex] = data;
}

NData SPop(Stack *stack) {
	int ret;
	if (SIsEmpty(stack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}
		

	ret = stack->data[stack->topOfIndex];	
	stack->topOfIndex -=1;
	return ret;
}

NData SPeek(Stack *stack) {
	int ret;
	if (SIsEmpty(stack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	ret = stack->data[stack->topOfIndex];
	return ret;

}

