/*
 * Bai1.h
 *
 *  Created on: Oct 6, 2012
 *      Author: Windows7
 */

#ifndef BAI1_H_
#define BAI1_H_
struct node{
	int  x;
	struct  node * next;
};
int ngto(int k);
struct node*taonut(int x);
struct node*themvao(struct node*head,int  y);
struct node*taods(struct node*head,int n);

#endif /* BAI1_H_ */
