#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CLinkedList.h"
#include "Employee.h"

void main(void) {
	List plist;
	Employee *employee;
	Employee *ret;
	int i;

	char FIND_NAME[30] = "Park";
	int NEXT_ORDER = 7;

	ListInit(&plist);

	employee = (Employee*)malloc(sizeof(Employee));
	employee->empNo = 100;
	strcpy(employee->name, "Kim");
	LInsert(&plist, employee);

	employee = (Employee*)malloc(sizeof(Employee));
	employee->empNo = 200;
	strcpy(employee->name, "Lee");
	LInsert(&plist, employee);

	employee = (Employee*)malloc(sizeof(Employee));
	employee->empNo = 300;
	strcpy(employee->name, "Park");
	LInsert(&plist, employee);

	employee = (Employee*)malloc(sizeof(Employee));
	employee->empNo = 400;
	strcpy(employee->name, "Choi");
	LInsert(&plist, employee);

	if (LFirst(&plist, &ret)) {
		if (strcmp(ret->name, FIND_NAME) != 0) {
			for (i = 0; i < LCount(&plist) - 1; i++) {
				LNext(&plist, &ret);
				if (strcmp(ret->name, FIND_NAME) == 0) {
					break;
				}
			}
		}		
		for (i = 0; i < NEXT_ORDER; i++) {
			LNext(&plist, &ret);
		};

		printf("%s\n", ret->name);
	}

	if (LFirst(&plist, &ret)) {
		free(ret);

		for (i = 0; i < LCount(&plist)-1; i++) {
			LNext(&plist, &ret);
			free(ret);
		}
	}
}