#include <stdio.h>
#include"ExpressionTree.h"

int main(void) {
	BTreeNode *bt = MakeExpTree("12+3*");
	//printf("----Preorder------\n");
	//ShowPrefixTypeExp(bt);
	printf("----Inorder--------\n");
	ShowInfixTypeExp(bt);
	//printf("----Postorder------\n");
	//ShowPostfixTypeExp(bt);
	printf("Result : %d\n",EvaluateExpTree(bt));

	return 0;
}