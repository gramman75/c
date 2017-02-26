#include <stdio.h>	
#include "BinaryTree.h"

void Action(BTreeNode* node) {
	printf("%d\n", node->data);
}

void main(void) {
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode();
	BTreeNode* bt5 = MakeBTreeNode();

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);
	SetData(bt5, 5);

	MakeLeftSubNode(bt1, bt2);
	MakeRightSubNode(bt1, bt3);

	MakeLeftSubNode(bt2, bt4);
	MakeRightSubNode(bt2, bt5);


	//printf("%d\n",GetData(GetRightSubNode(GetLeftSubNode(bt1))));

	PreoderTravers(bt1, Action);
	InorderTravers(bt1,Action);
	PostorderTravers(bt1, Action);
}
