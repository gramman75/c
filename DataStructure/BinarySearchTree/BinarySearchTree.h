#pragma once

#ifndef __BINARY_SEARCH_TREE
#define __BINARY_SEARCH_TREE

#include "BinaryTree2.h"

typedef BTData BSTData;

void BSTMakeAndInit(BTreeNode ** pRoot);

BSTData BSTGetNodeData(BTreeNode * bst);

void BSTInsert(BTreeNode ** pRoot, BSTData data);

BTreeNode* BSTSearch(BTreeNode * bst, BSTData data);

#endif // !___BINARY_SEARCH_TREE

