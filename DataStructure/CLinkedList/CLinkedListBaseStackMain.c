#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedListBaseStack.h" 
#include "Employee.h"

void main(void) {
	Stack stack;
	Employee *employee;
	StackInit(&stack);

	employee = (Employee*)malloc(sizeof(Employee));
	employee->empNo = 100;
	strcpy(employee->name, "Kim");
	SPush(&stack, employee);

	employee = (Employee*)malloc(sizeof(Employee));
	employee->empNo = 200;
	strcpy(employee->name, "Lee");
	SPush(&stack, employee);

	employee = (Employee*)malloc(sizeof(Employee));
	employee->empNo = 300;
	strcpy(employee->name, "Park");
	SPush(&stack, employee);

	employee = (Employee*)malloc(sizeof(Employee));
	employee->empNo = 400;
	strcpy(employee->name, "Choi");
	SPush(&stack, employee);

	while (!SIsEmpty(&stack)) {
		printf("%s\n", SPop(&stack)->name);
	}

}