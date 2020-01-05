/*
 * stackLinked.h
 *
 *  Created on: Apr 4, 2012
 *      Author: hoannh
 */

#ifndef STACKLINKED_H_
#define STACKLINKED_H_
struct node{
	int data;
	struct node* next;
};

int empty(struct node *s);
struct node* push(struct node *s,int data);
struct node* pop(struct node *s,int *data);
void init(struct node* s);


#endif /* STACKLINKED_H_ */
