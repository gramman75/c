#include "ExpressionTree.h"
#include "ListBaseStack.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void Action(BTreeNode *bt) {
	if (bt->data >= 0 && bt->data <= 9)
		printf("%d", bt->data);
	else
		printf("%c", bt->data);
}
BTreeNode * MakeExpTree(char exp[]) {
	// 12+3* = (1+2)*3 = 9
	Stack stack;
	BTreeNode *node;
	int len = strlen(exp);
	char ch;
	StackInit(&stack);

	for (int i = 0; i < len; i++) {
		ch = exp[i];
		node = MakeBTreeNode();

		if (isdigit(ch)) {
			SetData(node, ch - '0');
		}
		else {
			MakeRightSubNode(node, SPop(&stack));
			MakeLeftSubNode(node, SPop(&stack));
			SetData(node, ch);
		}
		SPush(&stack, node);
	}

	return SPop(&stack);
}
int EvaluateExpTree(BTreeNode *bt) {
	int op1, op2;

	/*op1 = GetData(GetLeftSubNode(bt));
	if (op1 < 0 || op1 > 9)
		op1 = EvaluateExpTree(GetLeftSubNode(bt));

	op2 = GetData(GetRightSubNode(bt));

	if (op2 < 0 || op2 > 9)
		op2 = EvaluateExpTree(GetRightSubNode(bt));*/

	if (GetLeftSubNode(bt) == NULL || GetRightSubNode(bt) == NULL)
		return GetData(bt);

	op1 = EvaluateExpTree(GetLeftSubNode(bt));
	op2 = EvaluateExpTree(GetRightSubNode(bt));

	switch (GetData(bt))
	{
	case '+':
		return op1 + op2;
		break;
	case '-':
		return op1 - op2;
		break;
	case '*':
		return op1*op2;
		break;
	case '/':
		op1 / op2;
		break;
	default:
		break;
	}
	return 0;
}

void ShowPrefixTypeExp(BTreeNode *bt) {
	PreorderTravers(bt, Action);
}
void ShowInfixTypeExp(BTreeNode *bt) {
	if (bt == NULL)
		return;

	if (bt->left != NULL || bt->right != NULL)
		printf("(");

	ShowInfixTypeExp(bt->left);
	Action(bt);
	ShowInfixTypeExp(bt->right);

	if (bt->left != NULL || bt->right != NULL)
		printf(")");
}
void ShowPostfixTypeExp(BTreeNode *bt) {
	PostorderTravers(bt, Action);
}