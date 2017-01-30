#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "InfixToPostfix.h"
#include "ListBaseStack.h"
#include "PostCalculator.h"

void main(void) {
	char exp[] = "((1-2)+3)*(5-2)*(9-4 +(3+2))";
	int len = strlen(exp);
	char *originExp = (char*)malloc(len + 1);
	strcpy(originExp, exp);
	int result;

	ConvertToPostfix(exp);
	result = EvalRPNExp(exp);

	printf("%s  = %d\n", originExp, result);
}