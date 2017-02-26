#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

void SetData(BTreeNode* node, BTData data) {
	node->data = data;
}

BTData GetData(BTreeNode* node) {
	return node->data;
}

BTreeNode* MakeBTreeNode(void) {
	BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

BTreeNode* GetLeftSubNode(BTreeNode* node) {
	return node->left;
	//if (node->left != NULL)
	//	return node->left;
	//else
	//	return NULL;
}

BTreeNode* GetRightSubNode(BTreeNode* node) {
	return node->right;
}

void MakeLeftSubNode(BTreeNode* main, BTreeNode* sub) {
	if (main->left != NULL)
		free(main->left);

	main->left = sub;
}

void MakeRightSubNode(BTreeNode* main, BTreeNode* sub) {
	if (main->right != NULL)
		free(main->right);

	main->right = sub;
}

void PreorderTravers(BTreeNode *node, VisitFuncPtr action){
	if (node == NULL)
		return;

	action(node);
	PreorderTravers(node->left, action);
	PreorderTravers(node->right, action);
}

void InorderTravers(BTreeNode *node, VisitFuncPtr action) {
	if (node == NULL)
		return;

	InorderTravers(node->left, action);
	action(node);
	//printf("%d\n", node->data);
	InorderTravers(node->right, action);
}

void PostorderTravers(BTreeNode *node, VisitFuncPtr action) {
	if (node == NULL)
		return;

	PostorderTravers(node->left, action);
	PostorderTravers(node->right, action);
	action(node);
}
