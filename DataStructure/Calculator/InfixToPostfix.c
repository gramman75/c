#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "InfixToPostfix.h"

int GetPrecOp(char ch) {
	switch (ch)
	{
	case '+':
	case '-':
		return 3;
	case '*':
	case '/':
		return 5;
	case '(':
		return 0;

	}

	return -1;
}

int WhoPrecOp(char ch1, char ch2) {
	int op1 = GetPrecOp(ch1);
	int op2 = GetPrecOp(ch2);

	if (op1> op2)
		return 1;
	else if (op1<op2 )
		return -1;

	return 0;
}


void ConvertToPostfix(char exp[]) {
	Stack stack;
	int len = strlen(exp), idx=0;
	char popOp, topOp;

	char* convExp = (char*)malloc(len+1);

	memset(convExp, 0, sizeof(char)*len+1);


	StackInit(&stack);

	for (int i = 0; i < len; i++) {
		char ch = exp[i];

		if (isdigit(ch)) {
			convExp[idx++] = ch;
		}
		else {
			switch (ch)
			{
			case '(':
				SPush(&stack, ch);
				break;
			case ')':
				while (1) {
					popOp = SPop(&stack);
					if (popOp == '(')
						break;
					else
						convExp[idx++] = popOp;
				}
				break;			
			case '+': case '-':
			case '*': case '/':
				while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), ch) >= 0)
					convExp[idx++] = SPop(&stack);

				SPush(&stack, ch);
				break;
			}
		}
	}

	while(!SIsEmpty(&stack))
		convExp[idx++] = SPop(&stack);

	strcpy(exp, convExp);
	//strcpy_s(exp, sizeof(exp)+1, convExp);
	free(convExp);

}