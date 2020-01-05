/*
 * songuyento.c
 *
 *  Created on: Oct 12, 2012
 *      Author: NgoHuong
 */

#include "songuyento.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
};

int kt_primeNumber(int n)
{
	int i;
	if (n<2)
		return 0;
	for (i=2; i<=n/2; i++)
		if (n%i==0)
			return 0;
	return 1;
}

struct Node *addNode(struct Node *list, int n)// list=NULL trong main
{
	struct Node *p;
	p = (struct Node*)malloc(sizeof(struct Node));
	p->data = n;
	p->next = list;
	list = p;
	return list;
}

struct Node *doiCho(struct Node *list)//q, last=null;
{
	struct Node *p, *q, *last;
	last = NULL; //p = NULL;
	if (list == NULL)
		printf("\nDanh sach rong,");
	else
	{
		for (p=list; p!=NULL; p=p->next)
		{
			q = (struct Node*)malloc(sizeof(struct Node));
			q->data=p->data;
			q->next=last;
			last=q;
		}
		return last;
	}
}

void in_ds(struct Node *list)
{
	struct Node *p;
	if (list == NULL)
	{
		printf("\nDanh sach rong,");
		return ;
	}
	for (p=list; p!=NULL; p=p->next)
	{
		printf("%5d", p->data);
	}
}

