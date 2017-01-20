#pragma once

#ifndef __DB_LINKED_LIST__
#define __DB_LINKED_LIST__

#define TRUE	1
#define FALSE	0

typedef int NData;


typedef struct _node
{
	NData data;
	struct _node *prev;
	struct _node *next;
} Node;

typedef struct _list
{
	Node* head;
	Node* tail;
	Node* cur;
	int numOfData;
} DBLinkedList;

typedef DBLinkedList List;

void ListInit(List* plist);
void LInsert(List* plist, NData data);

int LFirst(List* plist, NData* data);
int LNext(List* plist, NData* data);
NData LRemove(List* plist);
int NCount(List* plist);





#endif // !__DB_LINKED_LIST__

