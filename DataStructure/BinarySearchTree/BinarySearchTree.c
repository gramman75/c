#include <stdio.h>
#include "BinarySearchTree.h"

void BSTMakeAndInit(BTreeNode ** pRoot) {
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst) {
	return bst->data;
}

void BSTInsert(BTreeNode ** pRoot, BSTData data) {
	BTreeNode * pNode = NULL;
	BTreeNode * cNode = *pRoot;
	BTreeNode * nNode = NULL;

	while (cNode != NULL) {

		pNode = cNode;

		if (GetData(cNode) > data) {
			cNode = GetLeftSubTree(cNode);
		}
		else {
			cNode = GetRightSubTree(cNode);
		}
	}

	nNode = MakeBTreeNode();
	SetData(nNode, data);
	if (pNode != NULL) {
		if (GetData(pNode) > data) {
			MakeLeftSubTree(pNode, nNode);
		}
		else {
			MakeRightSubTree(pNode, nNode);
		}
	}
	else {
		*pRoot = nNode;
	}
}

BTreeNode* BSTSearch(BTreeNode * bst, BSTData data) {
	BTreeNode * cNode;
	BSTData cd;
	cNode = bst;


	while (cNode != NULL) {
		cd = GetData(cNode);

		if (cd == data) {
			return cNode;
		}
		else if (cd > data) {
			cNode = GetLeftSubTree(cNode);
		}
		else {
			cNode = GetRightSubTree(cNode);
		}
	}

	return NULL;


}