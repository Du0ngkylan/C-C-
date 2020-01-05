/*
 * linklist.h
 *
 *  Created on: Mar 19, 2012
 *      Author: hoannh
 */

#ifndef LINKLIST_H_
#define LINKLIST_H_

typedef struct student{
	char name[20];
	struct student *next;
}student;

int n;
struct student* creatElement(char[]);
struct student* addElement(struct student* ,char []);
struct student* doctep(char *);
void printList(struct student*);
int compare(void *,void *);
void sortList(struct student *);
struct student *searchName(struct student*,char[]);


#endif /* LINKLIST_H_ */
