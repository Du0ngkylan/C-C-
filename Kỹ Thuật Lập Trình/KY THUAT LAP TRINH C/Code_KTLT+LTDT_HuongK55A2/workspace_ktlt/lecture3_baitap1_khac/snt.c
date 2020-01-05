/*
 * snt.c
 *
 *  Created on: Oct 12, 2012
 *      Author: NgoHuong
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
}Node;

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

struct Node *doiCho(struct Node *list)//p=NULL
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


int main()
{
	setbuf(stdout, NULL);
	struct Node *list;
	list = NULL;
	int n, i;
	printf("\nNhap n= ");scanf("%d", &n);
	for (i=n; i>0; i--)
	{
		if (kt_primeNumber(i)==1)
		{
			list = addNode(list, i);
		}
	}
	printf("\nDanh sach so nguyen to:\n");
	in_ds(list);
	struct Node *q;
	q = doiCho(list);
	printf("\nDanh sach da doic ho la:\n");
	in_ds(q);
	return 0;

}
