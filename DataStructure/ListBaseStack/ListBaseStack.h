#pragma once

#ifndef __LB_STACK_H
#define __LB_STACK_H

#define	TRUE	1;
#define FALSE	0;

typedef int NData;

typedef struct _node {
	NData data;
	struct _node* next;
} Node;

typedef struct _ListStack
{
	Node* head;
	int numOfCount;
	
} ListStack;

typedef ListStack Stack;
void StackInit(Stack *pstack);
int SIsEmpty(Stack *pstack);

void SPush(Stack *pstack, NData data);
NData SPop(Stack *pstack);
NData SPeek(Stack *pstack);

#endif // !__LB_STACK_H

