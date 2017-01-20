#include <stdio.h>
#include <stdlib.h>

typedef struct __node
{
	int data;
	struct __node* next;
} Node;


void main(void) {
	Node* head = NULL;
	Node* tail = NULL;
	Node* cur = NULL;
	Node* newNode = NULL;


	int readData = 1;
	head = (Node*)malloc(sizeof(Node));
	tail = head;

	while (1) {
		printf("Number : ");
		scanf("%d", &readData);

		if (readData < 1)
			break;

		newNode = (Node*)malloc(sizeof(Node));

		newNode->data = readData;
		newNode->next = NULL;

		//if (head == NULL)
		//	head = newNode;
		//else
		//	tail->next = newNode;

		tail->next = newNode;
		tail = newNode;
	}


	if (head != tail) {
		printf("입력받은 Data출력\n");
		cur = head;
		while (cur->next != NULL) {
			cur = cur->next;
			printf("%d\t", cur->data);
		}
	}

	putchar('\n');

	if (head != NULL) {
		cur = head;
		while (cur->next != NULL) {
			if (cur->data == 2)
				break;
			else
				cur = cur->next;
		}

		if (cur->next == NULL)
			printf("Can not found\n");
		else
			printf("Find : %d\n", cur->data);
	}

	if (head != NULL) {
		printf("메모리 해제\n");
		Node* delNode = head;
		Node* nextDelNode = head->next;

		while (nextDelNode != NULL) {
			delNode = nextDelNode;
			nextDelNode = delNode->next;

			printf("삭제 %d\n", delNode->data);
			free(delNode);
		}
	}
}