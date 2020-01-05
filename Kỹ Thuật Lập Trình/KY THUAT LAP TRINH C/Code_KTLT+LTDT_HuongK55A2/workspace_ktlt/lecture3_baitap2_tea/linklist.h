/*
 * linklist.h
 *
 *  Created on: Mar 15, 2012
 *      Author: ChiNV
 */

#ifndef LINKLIST_H_
#define LINKLIST_H_

typedef struct Student {
	char name[20];
	int age;
	struct Student *next;
}Student;

struct Student* createElement(char [], int );
struct Student* addElement(struct Student*, char [], int );
struct Student* createList();
void printList(struct Student *);
int compare(void*, void*);
void sortList(struct Student *);
struct Student *searchName(struct Student*, char []);
#endif /* LINKLIST_H_ */
