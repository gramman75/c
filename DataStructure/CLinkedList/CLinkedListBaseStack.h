#pragma once

#ifndef __LB_STACK_H
#define __LB_STACK_H

#include "CLinkedList.h"

typedef CList Stack;
void StackInit(Stack *pstack);
int SIsEmpty(Stack *pstack);

void SPush(Stack *pstack, LData data);
LData SPop(Stack *pstack);
LData SPeek(Stack *pstack);

#endif // !__LB_STACK_H
