/*
 * chuyendoi.c
 *
 *  Created on: Jan 1, 2002
 *      Author: Student
 */
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"
void xuly();
char s[100];

struct Node {
	int element;
	struct Node *next;
};
struct Node *stack = NULL;

void push(int element) {
	struct Node* node = (struct Node*) malloc(sizeof(struct Node));
	if (node != NULL) {
		node->element = element;
		node->next = stack;
		stack = node;
	}
}

int pop() {
	if (stack != NULL) {
		struct Node *p = stack;
		int element = p->element;
		stack = stack->next;
		free(p);
		return element;
	} else {
		return 0;
	}
}
int isEmpty() {
	if (stack == NULL)
		return 1;
	return 0;
}
int isoperator(char c) {
	switch (c) {
	case '(':
		return 1;
	case ')':
		return 1;
	case '-':
		return 2;
	case '+':
		return 2;
	case '*':
		return 3;
	case '/':
		return 3;
	default:
		return 0;
	}
}
void createNode() {
	FILE *f;
	f = fopen("bieuthuc.txt", "r");
	if (!f) {
		printf("loi mo tep");
		exit(0);
	}
	fgets(s, 100, f);
	fclose(f);
	puts("day nhan dc la");
	printf("%s", s);
	puts("");
	xuly();
}
void xuly() {
	int i;
	for (i = 0; i < strlen(s); i++) {
		if (s[i] != ' ') {
			if (isoperator(s[i]) == 0)
				printf("%c", s[i]);
			else {
				if (s[i] == '(')
					push(s[i]);
				else if (s[i] == ')') {
					char c;
					do {
						c = pop();
						if (c != '(')
							printf("%c", c);
					} while (c != '(');
				} else {
					if (isEmpty() == 1)
						push(s[i]);
					else {
						char c;
						do {
							c = pop();
							if (isoperator(c) >= isoperator(s[i])) {
								printf("%c", c);
							} else {
								push(c);
								push(s[i]);
								break;
							}
						} while (1);
					}
				}
			}
		}

	}
	while (!isEmpty()) {
		printf("%c", pop());
	}
}
//tinh ra kq
void tinh() {
	int i;
	for (i = 0; i < strlen(s); i++) {
		if (isoperator(s[i] == 0)) {
			char c = s[i];
			push(atoi(&c)); // atoi chuyen 1 sau thanh 1 so
		} else {
			int kq=0;
			int t1 = pop();
			int t2 = pop();
			switch (s[i]) {
			case '+':
				kq = t2 + t1;
				break;
			case '-':
				kq = t2 - t1;
				break;
			case '*':
				kq = t2 * t1;
				break;
			case '/':
				kq = t2 / t1;
				break;
			}
			push(kq);
		}
	}
	printf("kq la: %d",pop());
}
int main() {
	setbuf(stdout, NULL);
	createNode();
	tinh();
	return 0;
}
