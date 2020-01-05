/*
 * sinhvien.h
 *
 *  Created on: Oct 30, 2012
 *      Author: ADMIN
 */

#ifndef SINHVIEN_H_
#define SINHVIEN_H_

typedef struct node{
	char data[20];
	int tanso;
	int diem;
	struct node *next;
}node;
node *doctep(node *);
node *createElement(char *,int);
node *addElement(node *,char *,int);
void printQueue(node *);
//node *sapxep(node *);
//node *xoa(node *,char *);
//node *chen(node *,char *);
void in(node *);


#endif /* SINHVIEN_H_ */
