#include <stdio.h>
#include "BinarySearchTree.h"

void main(void) {
	BTreeNode * bstRoot;
	BTreeNode * sNode;

	BSTMakeAndInit(&bstRoot);

	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 5);
	BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 8);
	BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 0);

	sNode = BSTSearch(bstRoot, 6);

	printf("%d", GetData(sNode));


}