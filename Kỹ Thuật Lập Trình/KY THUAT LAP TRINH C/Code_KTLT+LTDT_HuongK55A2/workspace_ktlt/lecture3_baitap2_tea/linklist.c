/*
 * linklist.c
 *
 *  Created on: Mar 15, 2012
 *      Author: ChiNV
 */

#include "linklist.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
struct Student* createElement(char name[], int age) {
	struct Student *student;
	student = (struct Student*)malloc(sizeof(struct Student));
	if( student != NULL) {
		strcpy( student->name, name);
		student->age = age >= 0 ? age : 0;
		student->next = NULL;
	}
	return student;
}

struct Student* addElement(struct Student* listStudent, char name[], int age) {
	struct Student *std = createElement(name, age);
	if( std != NULL) {
		std->next = listStudent;
		listStudent = std;
	}
	return listStudent;
}

struct Student* createList() {
	int n = 0;
	do {
		printf("size of list: ");
		scanf( "%d", &n);
	}while( n <= 0);

	struct Student *listStudent = NULL;
	int i = 0;
	printf("Nhap thong tin sinh vien (ten, tuoi): \n");
	char name[20];
	int age;
	for (i = 0; i < n; i++) {
		printf("Sinh vien thu %d: \n", i + 1);
		fflush(stdin);
		gets(name);
		scanf("%d", &age);
		listStudent = addElement( listStudent, name, age);
	}
	return listStudent;
}

void printList(struct Student *listStudent) {
	if( listStudent == NULL) {
		printf("Danh sach rong!\n");
	} else {
		struct Student *p;
		p = listStudent;
		while( p != NULL) {
			printf("{%s-%d}", p->name, p->age);
			p = p->next;
		}
		printf("\n");
	}
}

int compare(void* std1, void*std2) {
	struct Student* s1 = (struct Student*)std1;
	struct Student* s2 = (struct Student*)std2;
	return strcmp( s1->name, s2->name);
}

void sortList(struct Student *listStudent) {
	if( listStudent != NULL && listStudent->next != NULL) {
		struct Student *p, *q;
		p = listStudent;

		char name[20];
		int age;
		while( p->next != NULL) {
			q = p ->next;
			while( q != NULL) {
				if( strcmp( p->name, q->name) > 0) {
					strcpy( name, p->name);
					strcpy( p->name, q->name);
					strcpy( q ->name, name);

					age = p->age;
					p->age = q->age;
					q->age = age;
				}
				q = q->next;
			}
			p = p->next;
		}
	}
}
struct Student *searchName(struct Student* listStudent, char name[]) {
	if( listStudent == NULL)
		return NULL;
	else {
		struct Student *p;
		p = listStudent;
		while( p != NULL) {
			if( strcmp(p->name, name) == 0)
				return p;
			p = p->next;
		}
	}
	return NULL;
}
