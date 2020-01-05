/*
 * queue.h
 *
 *  Created on: Oct 6, 2012
 *      Author: MSS THUY
 */

#ifndef QUEUE_H_
#define QUEUE_H_

typedef struct node{
	char data[20];
	int tanso;
	struct node *next;
}node;
node *doctep(node *);
node *createElement(char *);
node *addElement(node *,char *);
void printQueue(node *);
node *sapxep(node *);
node *xoa(node *,char *);
node *chen(node *,char *);
void in(node *);

#endif /* QUEUE_H_ */
