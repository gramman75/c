#include <stdio.h>
#include "InfixToPostfix.h"

void main(void) {
	char exp[] = "((1-2)+3)*(5-2)";

	ConvertToPostfix(exp);

	printf("%s", exp);
}