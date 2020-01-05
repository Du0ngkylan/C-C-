/*
 * danhsach_sv.c
 *
 *  Created on: Oct 11, 2012
 *      Author: NgoHuong
 *cai dat 1 danh sach gom n sinh vien
 *tao 1 dsmn ten doc tu tep
 *sap xep ten theo a,b,c..
 *nhap 1 ten tu ban phim, chen vao ds ma khong lam mat sx dung do(tim vi tri va chen)
 *timkiem 1 ten tra ve vi tri con tro chua ten do(dung tuan tu)
 *tim cac node chua ten duoc nhap vao, xoa cac node do
 *free list
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "danhsach_sv.h"

struct Node
{
	char name[30];
	struct Node *next;
};

//struct Node *head = NULL;

struct Node *addNode(struct Node *list, char name[])// khoi tao list=NULL o main
{
	struct Node *p;

	//if (p!=NULL)
	//{
		p = (struct Node *)malloc(1*sizeof(struct Node));
		strcpy(p->name, name);
		p->next=list;
		list=p;
	//}
	return list;
}

//ham doc tu tep

struct Node* readList(struct Node *list)
{
	int n, i;
	FILE *f;

	f = fopen("dssv.txt", "r");
	if (f==NULL)
	{
		printf("Loi mo tep");
		exit(0);
	}
	fscanf(f, "%d", &n);
	for (i=0; i<n; i++)
	{
		char name[30];
		fgets(name, 30, f);name[strlen(name)-1] = '\0' ;
		list = addNode(list, name);
	}
	//gets(p->name, 30, f);
	fclose(f);
	return list;
}

//ham sap xep ten sv theo thu tu alphabetically

void sortList(struct Node *list)
{
	struct Node *p, *q;
	//p=list;
	//q=p->next;
	if (list == NULL)
	{
		printf("Danh sach rong!");
		return ;
	}
	for (p=list; p->next!=NULL; p=p->next)
	{
		for (q=p->next; q!=NULL; q=q->next)
		{
			if (strcmp(p->name, q->name) > 0)
			{
				char t[30];
				strcpy(t, p->name);
				strcpy(p->name, q->name);
				strcpy(q->name, t);
			}
		}
	}
}

//chen them ptu ma khong lam pha vo sx cua danh sach

struct Node *insertNode(struct Node *list)// ten[] nhap o main//==> nham
{
	struct Node *p, *q;
	q = (struct Node*)malloc(sizeof(struct Node));
	char ten[30];
	printf("Nhap vao 1 ten:\t");
	fflush(stdin);
	gets (ten);
	strcpy(q->name, ten);
	if (list == NULL)
	{
		p->next = NULL;
		list = p;
	}
	else
	{
		for (p=list; p!=NULL; p=p->next )
		{
			if (q->name > p->name && q->name < p->next->name)//them vao giua 2 bon nay
			{
				q->next=p->next;
				p->next = p;
			}
		}
		return list;
	}
}

//ham tim kiem 1 ten tra ve vi tri chua con tro do




//ham xoa ten vua dc nhap vao

struct Node *deleteNode(struct Node *list)
{
	struct Node *p, *q;
	char ten[30];
	printf("\nNhap vao ten:");
	fflush(stdin);
	gets (ten);
	strcpy(q->name, ten);
	// xoa thi cos can cap phat khong nhi==>khong
	if (list == NULL)
	{
		printf("\nDanh sach rong");
		return ;
	}
	for (p=list; p!=NULL; p=p->next)
	{
		if (strcmp(p->name, q->name)==0)
		{
			struct Node *d;
			d = p->next;
			p->next = p->next->next;
			free(d);
		}

	}
	return p;
}

// ham in danh sach

void in_ds(struct Node *list)
{
	struct Node *p;
	if (list==NULL)
	{
		printf("\nDanh sach rong");
		return ;
	}
	for (p=list; p!=NULL; p=p->next)
	{
		printf ("%s\n", p->name);
	}
}
// ham free

/*void free(struct Node *list)
{
	struct Node *p;
	for (p=list; p!=NULL; p=p->next)
	{
		list = p->next;
		free(p);
	}
}*/



