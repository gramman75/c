#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ListBaseStack.h"
#include "PostCalculator.h"
#include <ctype.h>

int EvalRPNExp(char exp[]) {
	Stack digitStack;

	StackInit(&digitStack);

	int len = strlen(exp);
	char ch;
	char op1, op2;



	for (int i = 0; i < len; i++) {
		ch = exp[i];

		if (isdigit(ch))
			SPush(&digitStack, ch-'0');
		else {
			op2 = SPop(&digitStack);
			op1 = SPop(&digitStack);
			switch (ch)
			{
			case '+':
				SPush(&digitStack, op1 + op2);
				break;
			case '-':
				SPush(&digitStack, op1 - op2);
				break;
			case '*':
				SPush(&digitStack, op1 * op2);
				break;
			case '/':
				SPush(&digitStack, op1 / op2);
				break;
			default:
				break;
			}

		}

	}

	return (SPop(&digitStack));

}