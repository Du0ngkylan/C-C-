/*
 * IntoPost.c
 *
 *  Created on: Nov 28, 2012
 *      Author: ADMIN
 */
#include  <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IntoPost.h"

char stack[100];
int top = 0, len = 0;
char str[100];
char ss[100];

int DocDuLieu(char *fi) {
	int n;
	FILE *f;
	f = fopen(fi, "r");
	n = 0;
	//while (!feof(f))
	{
		fgets(str, 100, f);
		//	if( str[strlen(str) - 1] ='\n')
		//	str[strlen(str) - 1] = 0;
		//fscanf(f,"%c",&str[n]);
		n = strlen(str);
	}
	fclose(f);
	return n;
}

int GetPriority(char c) {
	if (c == '*' || c == '/' || c == '%')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return 0;

}

void push(char c) {
	top++;
	stack[top] = c;
}

char pop() {
	if (top >= 0) {
		char x = stack[top];
		top--;
		return x;
	} else
		return 0;
}

void Change(int m) {
	int i = 0;
	char x;
	for (i = 0; i < m; i++) {
		if (GetPriority(str[i]) == 0 && str[i] != '(' && str[i] != ')') {
			printf("%c", str[i]);
			ss[len++] = str[i];
		} else if (str[i] == '(')
			push(str[i]);
		else if (str[i] == ')') {
			do {
				x = pop();
				if (x != '(') {
					printf("%c", x);
					ss[len++] = x;
				}
			} while (x != '(');
		} else {
			while (GetPriority(stack[top]) >= GetPriority(str[i])) {
				x = pop();
				if (x != '(') {
					printf("%c", x);
					ss[len++] = x;
				}
			}
			push(str[i]);
		}
	}

	while (top >= 0) {
		x = pop();
		if (x != '(') {
			printf("%c", x);
			ss[len++] = x;
		}
	}
	ss[len] = 0;
	printf("%s", ss);
}

void xuly1() {
	int i;
	for (i = 0; i < strlen(ss); i++) {
		if (isoperator(ss[i]) == 0) {
			char c = ss[i];
			push(atoi(&c)); // chuyen 1 sau thanh 1 so;
		} else {
			int kq;
			int t1 = pop();
			int t2 = pop();
			switch (ss[i]) {
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
	printf("\nket qua la:%d", pop());
}
