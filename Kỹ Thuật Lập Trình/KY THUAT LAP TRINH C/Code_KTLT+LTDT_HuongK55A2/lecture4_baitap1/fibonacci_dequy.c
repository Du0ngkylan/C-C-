/*
 * bai1.c
 *
 *  Created on: Oct 15, 2012
 *      Author: Student
 */

#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n)
{
	if(n < 2)
		return n;
	else
		return fibonacci(n-1) + fibonacci(n-2);
}

typedef struct Node
{
	int data;
	struct Node *next;
}Node;

Node *addList(struct Node *list, int n)//khoi tao list=NULL o main
{
	Node *p;

	int i;
	for (i=0; fibonacci(i)<n; i++)
	{
		p = (Node*)malloc(sizeof(Node));


			p->data=fibonacci(i);
			p->next=list;
			list=p;

	}
	return list;
}

void in_ds( Node *list)
{
	Node *p;
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

int main()
{
	setbuf(stdout, NULL);
	int n;
	printf("\nNHap n= "); scanf("%d", &n);
	Node *list, *p;
	list = NULL;
	p = addList(list, n);
	printf("\nday so fibonacci la:\n");
	in_ds(p);
	return 0;
}
