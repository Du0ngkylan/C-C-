/*
 * InToPost-1.c
 *
 *  Created on: Nov 29, 2012
 *      Author: ADMIN
 */
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "InToPost-1.h"

int len = 0;

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
	case '%':
		return 3;
	default:
		return 0;
	}
}

void xuly() {
	int i;

	for (i = 0; i < strlen(s); i++) {
		if (s[i] != ' ') {
			if (isoperator(s[i]) == 0) {

				//printf("%c", s[i]);
				ss[len++] = s[i];
			} else {
				if (s[i] == '(')
					push(s[i]);
				else if (s[i] == ')') {
					char c;
					do {
						c = pop();
						if (c != '(') {
							//printf("%c", c);
							ss[len++] = c;
						}
					} while (c != '(');
				} else {
					if (isEmpty() == 1)
						push(s[i]);
					else {
						char c;
						do {
							c = pop();
							if (isoperator(c) >= isoperator(s[i])) {
								//printf("%c", c);
								ss[len++] = c;
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
		ss[len++] = pop();
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
