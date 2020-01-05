/*
 * InToPost-1.h
 *
 *  Created on: Nov 29, 2012
 *      Author: ADMIN
 */

#ifndef INTOPOST_1_H_
#define INTOPOST_1_H_

struct Node {
	int element;
	struct Node *next;
};
char ss[100];
char s[100];
int isoperator(char);
int isEmpty();
void doctep();
void push(int);
int pop();
void xuly();
void xuly1();

#endif /* INTOPOST_1_H_ */
