/*
 * baitap.c
 *
 *  Created on: Nov 23, 2012
 *      Author: HongMo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
	char c;
	struct Node *next;
};
struct Node *stack = NULL;
int isEmpty() {
	if (stack == NULL)
		return 1;
	else
		return 0;
}
void push(char s) {
	struct Node *p;
	p = (struct Node*) malloc(sizeof(struct Node));
	if (p != NULL) {
		p->c = s;
		p->next = stack;
		stack = p;
	}
}
char pop() {
	if (stack != NULL) {
		struct Node *p;
		p = stack;
		char c = p->c;
		stack = p->next;
		free(p);
		return c;
	} else {
		return 0;
	}
}
int isoperator(char c) {
	switch (c) {
	case '(':
		return 1;
	case ')':
		return 1;
	case '+':
		return 2;
	case '-':
		return 2;
	case '*':
		return 3;
	case '/':
		return 3;
	default:
		return 0;
	}
}
void xuli(char s[40]) {
	int i;
	FILE *f;
	f = fopen("output.txt", "w");
	for (i = 0; i < strlen(s); i++) {
		if (s[i] != ' ') {
			if (isoperator(s[i]) == 0) {
				printf("%c", s[i]);
				fprintf(f, "%c", s[i]);
			} else {
				if (s[i] == '(') {
					push(s[i]);
				} else if (s[i] == ')') {
					char c;
					do {
						c = pop();
						if (c != '(') {
							printf("%c", c);
							fprintf(f, "%c", c);
						}
					} while (c != '(');
				} else {
					if (isEmpty()) {
						push(s[i]);
					} else {
						char c;
						do {
							c = pop();
							if (isoperator(c) >= isoperator(s[i])) {
								printf("%c", c);
								fprintf(f, "%c", c);
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
		char c = pop();
		printf("%c", c);
		fprintf(f, "%c", c);
	}

	fclose(f);
}

void xuly2(char s[]) { //bai tap tinh toan
	int i;
	//printf("\n***s = %s***\n", s);
	for (i = 0; i < strlen(s); i++) {
		if (s[i] != ' ') {
			if (isoperator(s[i]) == 0) {
				char c = s[i];
				int t = atoi(&c);
				push(t);
			} else {
				int t1 = pop();
				int t2 = pop();
				int kq;
				switch (s[i]) {
				case '+':
					kq = t1 + t2;
					break;
				case '-':
					kq = t2 - t1;
					break;
				case '*':
					kq = t1 * t2;
					break;
				case '/':
					kq = t1 / t2;
					break;
				}
				push(kq);
			}
		}
	}
	printf("\nkq la:%d", pop());
}
int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	char s[40];
	printf("nhap vao mot bieu thuc toan hoc:\n");
	gets(s);
	xuli(s);
	FILE *f;
	f = fopen("output.txt", "r");
	while (!feof(f)) {
		fgets(s, 100, f);
	}
	xuly2(s);
	return 0;
}

