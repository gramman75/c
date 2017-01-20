#pragma once

#ifndef __DBLINKED_LIST__
#define __DBLINKED_LIST__

#define FALSE	0
#define TRUE	1

typedef int LData;

typedef struct _node
{
	LData data;
	struct _node *prev;
	struct _node *next;
} Node;

typedef struct _list
{
	Node *head;
	Node *cur;
	int numOfData;

} DBList;

typedef DBList List;

void ListInit(List* plist);
void LInsert(List* plist, LData data);
void LInsertFront(List* plist, LData data);

int LFirst(List* plist, LData* data);
int LNext(List* plist, LData* data);
int LPrevious(List* plist, LData* data);

LData LRemove(List* plist);
int LCount(List* plist);

#endif // !__DBLINKED_LIST__

