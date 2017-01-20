#pragma once
#include "Employee.h"

#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#define	TRUE	1
#define FALSE	0

typedef Employee *LData;

typedef struct _node {
	LData data;
	struct _node* next;
} Node;

typedef struct _list {
	Node* tail;
	Node* cur;
	Node* before;
	int numOfData;
} CList;

typedef CList List;

void ListInit(List* plist);
void LInsert(List* plist, LData data);
void LInsertFront(List* plist, LData data);

int LFirst(List* plist, LData* data);
int LNext(List* plist, LData* data);
LData LRemove(List* plist);
int LCount(List* plist);


#endif // !__C_LINKED_LIST_H__

