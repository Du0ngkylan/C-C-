/*
 * BT2.c
 *
 *  Created on: Aug 8, 2013
 *      Author: QuyenNT
 */
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct sinhvien{char name[20];struct sinhvien *next;}sinhvien;



sinhvien *createSV(char *s)
{
	sinhvien *stu = (sinhvien*)malloc(sizeof(sinhvien));
	if(stu!=NULL)
	{
		strcpy(stu->name,s);
		stu->next =NULL;
	}

	return stu;
}


sinhvien *addSV(sinhvien *head,char *s)
{
	sinhvien *stu = createSV(s);

	if(stu!=NULL)
	{
		stu->next = head;
		return stu;
	}
	else
		return head;
}

sinhvien *creatList(char *filename)
{
	sinhvien *head = NULL;
	char s[20];
	FILE *f;
	f=fopen(filename,"r");
	while(!feof(f))
	{
		fscanf(f,"%s",&s);
		head = addSV(head,&s);
	}

	return head;
}

void printList(sinhvien *head)
{
	sinhvien *p ;

	printf("\n-----Danh sach------\n");
	for( p = head; p!=NULL ; p = p ->next)
		printf("%s ",p->name);
}


void sortList(sinhvien *head)
{
	sinhvien *p,*q;

	for( p =head ; p->next!=NULL; p= p ->next)
		for(q = p->next;q!=NULL; q =q->next)
		{
			if(strcmp(p->name,q->name) > 0)
			{
				char s[20];
				strcpy(s,p->name);
				strcpy(p->name,q->name);
				strcpy(q->name,s);
			}
		}
}

sinhvien *insertSinhvien(sinhvien *head,char *s)
{
	sinhvien *stu = createSV(s);

	if(strcmp(head->name,s) >= 0)
	{
		stu->next = head;
		return stu;
	}
	else
	{
			sinhvien *p = head;
			sinhvien *q = p->next;

			while(q!=NULL && strcmp(s,q->name) > 0)
			{
				p=p->next;
				q=p->next;
			}

			if(q == NULL)
			{
				p->next = stu;
				return head;
			}
			else
			{
				p->next = stu;
				stu->next = q;
				return head;
			}
	}

}



int main()
{
	setbuf(stdout,NULL);
	sinhvien *listSV = NULL;

	listSV = creatList("danhsach.txt");
	printList(listSV);

	sortList(listSV);

	printList(listSV);

	char s[20];

	printf("\nnhap ten muon them: ");
	scanf("%s",&s);
	listSV = insertSinhvien(listSV,&s);

	printList(listSV);

	return 0;
}
