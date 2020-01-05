/*
 * on_prime_number.c
 *
 *  Created on: Dec 31, 2012
 *      Author: NgoHuong
 */
//cai dat 1 dsmm chua day so nguyen to < n
//in ds, va dao lai day do

#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
	int data;
	struct Node *next;
}Node;

int kt(int k)
{
	int i;
	if (k < 2) return 0;
	for (i=2; i<=k/2; i++)
	{
		if (k % 2 == 0)
			return 0;
	}
	return 1;
}

Node *addNode(Node *list, int n)
{
	Node *p;
	p = (Node *)malloc(sizeof(Node));
	p->data = n;
	p->next = list;
	list = p;
	return list;
}

Node *doi_cho(Node *list)
{
	Node *last, *p, *q;
	last = NULL;
	if (list == NULL)
	{
		printf("\nDanh sach rong!!");
	}else {
		for (p = list; p != NULL; p = p->next)
		{
			q = (Node *)malloc(sizeof(Node));
			q->data = p->data;
			q->next = last;
			last = q;
		}
		return last;
	}
}

void in_ds(Node *list)
{
	Node *p;
	if (list == NULL)
	{
		printf("\nDanh sach rong");
		return;
	}
	for (p = list; p != NULL; p=p->next)
	{
		printf("%d\t", p->data);
	}
}

int main()
{
	setbuf(stdout, NULL);
	Node *list, *q;
	list = NULL;
	int n, i;
	printf("\nNhap n= ");
	scanf("%d", &n);
	for (i=n ; i>0; i--)
	{
		if (kt(i) == 1)
		{
			list = addNode(list, i);
		}
	}
	printf("\nDanh sach so nguyen to la:\n");
	in_ds(list);
	q = doi_cho(list);
	printf("\nDanh sach da doi cho la:\n");
	in_ds(q);
	return 0;
}
