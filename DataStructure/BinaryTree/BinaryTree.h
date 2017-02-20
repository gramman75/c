#pragma once
#ifndef __BINARY_TREE_H
#define __BINARY_TREE_H

typedef int BTData;

typedef struct _btnode {
	BTData data;
	struct _btnode * left;
	struct _btnode * right;
} BTreeNode;


void SetData(BTreeNode *node, BTData data);
BTData GetData(BTreeNode *node);

BTreeNode* MakeBTreeNode(void);

BTreeNode* GetLeftSubNode(BTreeNode * node);
BTreeNode* GetRightSubNode(BTreeNode * node);

void MakeLeftSubNode(BTreeNode * main, BTreeNode * sub);
void MakeRightSubNode(BTreeNode * main, BTreeNode * sub);


typedef void VisitFuncPtr(BTreeNode *node);

void InorderTravers(BTreeNode *node,  VisitFuncPtr action);
#endif // !__BINARY_TREE_H
