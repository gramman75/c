#pragma once
#ifndef __BINARY_TREE
#define __BINARY_TREE

#define TRUE	1
#define FALSE	0

typedef int BTData;

typedef struct _node {
	BTData data;
	struct _node *left;
	struct _node *right;
} Node;

typedef Node BTreeNode;

BTreeNode * MakeBTreeNode(void);

BTData GetData(BTreeNode * bt);

void SetData(BTreeNode * bt, BTData data);

BTreeNode * GetLeftSubTree(BTreeNode *bt);
BTreeNode * GetRightSubTree(BTreeNode *bt);
void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub);
void MakeRightSubTree(BTreeNode *main, BTreeNode * sub);

#endif // !__BINARY_TREE

