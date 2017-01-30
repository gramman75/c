#include <stdio.h>
#include "PostCalculator.h"

void main(void) {
	printf("%d", EvalRPNExp("324*+"));
}