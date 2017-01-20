#pragma once
#ifndef __ARRAY_BASE_STACK__
#define __ARRAY_BASE_STACK__

#define TRUE	1
#define FALSE	0

#define MAX_LENGTH	100

typedef int NData;

typedef struct _array_stack
{
	NData data[MAX_LENGTH];
	int topOfIndex;
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack *stack);

NData SPop(Stack *stack);
NData SPeek(Stack *stack);
void SPush(Stack *stack, NData data);
int SIsEmplty(Stack *statck);


#endif // !__ARRAY_BASE_STACK__

