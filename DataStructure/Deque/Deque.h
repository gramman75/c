#pragma once
#ifndef __DEQUE
#define __DEQUE

#define TRUE	1
#define FALSE	0

typedef int NData;

typedef struct _node 
{
	NData data;
	struct _node * prev;
	struct _node * next;
} Node;

typedef struct _deque
{
	Node * head;
	Node * tail;
} LDeque;

typedef LDeque Deque;

void DqueueInit(Deque *dq);
int DQIsEmpty(Deque *dq);

void DQAddFirst(Deque *dq, NData data);
void DQAddLast(Deque *dq, NData data);

NData DQRemoveFirst(Deque *dq);
NData DQRemoveLast(Deque *dq);

NData DQGetFirst(Deque *dq);
NData DQGetLast(Deque *dq);

#endif // !__DEQUE

