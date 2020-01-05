/*
 * bai2.c
 *
 *  Created on: Oct 15, 2012
 *      Author: Student
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
}Node;

Node *addList(int n)
{
	Node *p, *list;
	list =NULL;
	p = (Node*)malloc(sizeof(Node));
	int a=0; int b=1; int c;
	p->data = a;
	p->next = list;
	list = p;
	while (1)
	{
		p = (Node*)malloc(sizeof(Node));
		c =a + b;
		a = b;
		b = c;
		if( a <= n) {
			p->data=a;
			p->next=list;
			list = p;
		} else
			break;
	}
	return list;
}

void in_ds( Node *list)
{
	struct Node *p;
	if (list == NULL)
	{
		printf("Loi");
		exit(0);
	}
	for (p=list; p!=NULL; p=p->next)
	{
		printf("%5d", p->data);
	}
}

int main ()
{
	setbuf(stdout, NULL);
	int n;
	printf("\nNhap n= "); scanf("%d", &n);
    Node *p;
    p=addList(n);
    in_ds(p);
    return 0;
}

