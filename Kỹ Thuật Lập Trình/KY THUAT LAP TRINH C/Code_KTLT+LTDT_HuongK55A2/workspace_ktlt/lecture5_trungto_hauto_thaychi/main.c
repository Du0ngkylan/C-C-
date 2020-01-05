/*
 * main.c
 *
 *  Created on: Nov 9, 2012
 *      Author: Student
 */
// dung

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
	char data;
	struct node *next;
};

struct node *stack = NULL;

void push(char data) {
	struct node *p;
	p = (struct node*) malloc(sizeof(struct node));
	if (p != NULL) {
		p->data = data;
		p->next = stack;
		stack = p;
	}
}
char pop() {
	if (stack != NULL) {
		struct node *p;
		p = stack;
		char data;
		data = p->data;
		stack = p->next;
		free(p);
		return data;
	} else {
		return 0;
	}
}
int ktra(char c) {
	if (c == '*' || c == '/' || c == '%')
		return 2;
	else if (c == '+' || c == '-') {
		return 1;
	} else
		return 0;
}

void printStack() {
	struct node *p;
	p = stack;
	while (p != NULL) {
		printf("%c   ", p->data);
		p = p->next;
	}
	puts("");
}
void xuly(char s[]) {
	int n = strlen(s);
	int i;
	for (i = 0; i < n; i++) {
		if (ktra(s[i]) == 0 && s[i] != ')' && s[i] != '(') {
			printf("%c", s[i]);
		} else if (s[i] == '(') {
			push(s[i]);
		} else if (s[i] == ')') {
			char x;
			do {
				x = pop();
				if (x != '(')
					printf("%c", x);
			} while (x != '(' && x != 0);
		} else {
			if (stack == NULL)
				push(s[i]);
			else {
				char x = pop();
				if (x != '(' && ktra(s[i]) <= ktra(x)) {
					printf("%c", x);
				} else {
					push(x);
				}
				push(s[i]);
			}
		}
	}
	while (stack != NULL) {
		printf("%c", stack->data);
		stack = stack->next;
	}
}
int main() {
	setbuf(stdout, NULL);
	char s[100];
	printf("nhap vao bieu thuc toan hoc : \n");
	gets(s);
	xuly(s);
	return 0;
}
