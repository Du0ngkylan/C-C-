/*
 * linklist.c
 *
 *  Created on: Mar 19, 2012
 *      Author: hoannh
 */
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "linklist_student.h"

/*typedef struct student{
	char name[20];
	struct student *next;
}student;*/

struct student *liststudent=NULL;

struct student* creatElement(char name[20]){
	struct student *student;
	student = (struct student *)malloc(sizeof(struct student));
	if(student != NULL){
		strcpy(student->name,name);
		student->next=NULL;
	}
	return student;
}
struct student* addElement(struct student* liststudent,char name[20]){
	struct student *std=creatElement(name);
	if(std!=NULL){
		std->next=liststudent;
		liststudent=std;
	}
	return liststudent;
}
struct student* doctep(char *fi){
	FILE *f;
	n=0;
	f=fopen(fi,"r");
	if(f==NULL) printf("Error file");
	else{
		char ten[20];
		while(!feof(f)){
			fgets(ten,30,f);
			n++;
			ten[strlen(ten)-1]=0;
			liststudent= addElement(liststudent,ten);
		}
	}
	return liststudent;
}

void printList(struct student* liststudent){
	student *p;
	for(p=liststudent;p!=NULL;p=p->next){
		printf("%s\n",p->name);
	}
}
void sort(struct student* liststudent){
	student*p;
	char *k;
	student*q;
	for(p=liststudent;p!=NULL;p=p->next){
		for(q=p->next;q!=NULL;q=q->next){
			if(strcmp(p->name,q->name)>0){
				strcpy(k,p->next);
				strcpy(p->next,q->next);
				strcpy(q->next,k);
			}
		}
	}
}
