/*
 * linklist.c
 *
 *  Created on: october 28, 2012
 *      Author: ThanhMeo
 */

#include "linklist.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
struct Student* createElement(char name[], float dtb) {
	struct Student *student;
	student = (struct Student*) malloc(sizeof(struct Student));
	if (student != NULL) {
		strcpy(student->name, name);
		student->dtb = dtb >= 0 ? dtb : 0;
		student->next = NULL;
	}
	return student;
}

struct Student* addElement(struct Student* listStudent, char name[], float dtb) {
	struct Student *std = createElement(name, dtb);
	if (std != NULL) {
		std->next = listStudent;
		listStudent = std;
	}
	return listStudent;
}
struct Student* addEnd(struct Student* listStudent, char name[], float dtb) {
	struct Student *std = createElement(name, dtb);
	if (std != NULL) {
		struct Student *end = listStudent;
		while (end->next != NULL) {
			end = end->next;
		}
		end->next = std;
	}
	return listStudent;
}
struct Student* readFile(char *file){
	FILE *f;
	int i,n;
	char s[200];
	f=fopen(file,"rt");
	if (!f) {
		puts("Loi doc tep");
		exit(0);
	}
	fscanf(f,"%d",&n);
	fgets(s,200,f);
	struct Student *listStudent = NULL;
	for (i = 0; i < n; ++i) {
		char name[30];
		float ave;
		fgets(name,30,f);
		name[strlen(name)-1]='\0';
		fscanf(f,"%f",&ave);
		listStudent = addElement(listStudent,name,ave);
		fgets(s,200,f);
	}

	return listStudent;
}
struct Student* createList() {
	int n = 0;
	do {
		printf("size of list: ");
		scanf("%d", &n);
	} while (n <= 0);

	struct Student *listStudent = NULL;
	int i = 0;
	printf("Nhap thong tin sinh vien (ten, diem trung binh): \n");
	char name[20];
	float dtb;
	for (i = 0; i < n; i++) {
		printf("Sinh vien thu %d: \n", i + 1);
		fflush(stdin);
		gets(name);
		scanf("%f", &dtb);
		listStudent = addElement(listStudent, name, dtb);
	}
	return listStudent;
}
struct Student* delList(struct Student *listStudent) {
	struct Student *temp = listStudent;
	while (temp != NULL) {
		struct Student *p = temp;
		temp = temp->next;
		free(p);
	}
	return NULL;
}
void printList(struct Student *listStudent) {
	if (listStudent == NULL) {
		printf("Danh sach rong!\n");
	} else {
		struct Student *p;
		p = listStudent;
		while (p != NULL) {
			printf("%s - %.2f\n", p->name, p->dtb);
			p = p->next;
		}
		printf("\n");
	}
}

int compare(void* std1, void*std2) {
	struct Student* s1 = (struct Student*) std1;
	struct Student* s2 = (struct Student*) std2;
	return strcmp(s1->name, s2->name);
}

void sortList(struct Student *listStudent) {
	if (listStudent != NULL && listStudent->next != NULL) {
		struct Student *p, *q;
		p = listStudent;

		char name[20];
		float dtb;
		while (p->next != NULL) {
			q = p->next;
			while (q != NULL) {
				if (strcmp(p->name, q->name) > 0) {
					strcpy(name, p->name);
					strcpy(p->name, q->name);
					strcpy(q->name, name);

					dtb = p->dtb;
					p->dtb = q->dtb;
					q->dtb = dtb;
				}
				q = q->next;
			}
			p = p->next;
		}
	}
}
struct Student *searchName(struct Student* listStudent, char name[]) {
	if (listStudent == NULL)
		return NULL;
	else {
		struct Student *p;
		p = listStudent;
		while (p != NULL) {
			if (strcmp(p->name, name) == 0)
				return p;
			p = p->next;
		}
	}
	return NULL;
}
