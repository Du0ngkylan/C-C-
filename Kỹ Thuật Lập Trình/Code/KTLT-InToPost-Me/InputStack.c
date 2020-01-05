/*
 * InputStack.c
 *
 *  Created on: Nov 29, 2012
 *      Author: ADMIN
 */
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "InToPost-1.h"

struct Node *stack = NULL;

void doctep() {
	FILE*f;
	f = fopen("dulieu.txt", "r");
	if (!f) {
		puts("loi mo tep");
		exit(0);
	}
	fgets(s, 100, f);
	fclose(f);
	puts("Day nhan duoc la:");
	printf("%s", s);
	puts(" ");
	puts("bieu thuc hau to la:");
	xuly();
}

void push(int element) {
	struct Node* node = (struct Node*) malloc(sizeof(struct Node));
	if (node != NULL ) {
		node->element = element;
		node->next = stack;
		stack = node;
	}
}

int pop() {
	if (stack != NULL ) {
		struct Node *p = stack;
		int element = p->element;
		stack = p->next;
		free(p);
		return element;
	} else {
		return 0;
	}
}

int isEmpty() {
	if (stack == NULL )
		return 1;
	return 0;
}

