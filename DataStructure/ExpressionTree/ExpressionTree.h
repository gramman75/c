#pragma once
#ifndef __EXPRESSION_TREE_H
#define __EXPRESSION_TREE_H

#include "BinaryTree.h"

BTreeNode * MakeExpTree(char exp[]);
int EvaluateExpTree(BTreeNode *bt);

void ShowPrefixTypeExp(BTreeNode *bt);
void ShowInfixTypeExp(BTreeNode *bt);
void ShowPostfixTypeExp(BTreeNode *bt);


#endif // !__EXPRESSION_TREE_H

