/*
 * hauto_tiento.c
 *
 *  Created on: Jan 10, 2013
 *      Author: NgoHuong
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//chua dung
typedef struct Node
{
	char s;
	struct Node *next;
}Node;

struct Node *stack = NULL;

int kt_rong()
{
	if (stack == NULL)
		return 0;
	return 1;
}

//day phan tu vao stack

void push(char s)
{
	Node *node = (Node *)malloc(sizeof(Node));
	if (node != NULL)
	{
		node->s = s;
		node->next = stack;
		stack = node;
	}
}

//lay mot phan tu ra khoi stack

int pop()
{
	if (stack != NULL)
	{
		Node *p;
		p = stack;
		char s;
		s = p->s;
		stack = p->next;
		free(p);
		return s;
	}
	return 0;
}

int uutien(char c)
{
	if (c == '(' || c == ')')
		return 1;
	else
		if (c == '+' || c == '-')
			return 1;
		else
			if (c == '*' || c == '/')
				return 2;
			else
				return 0;
}

void xuly(char s[])
{
	int i;
	int n = strlen(s);
	for (i=0; i<n; i++)
	{
		if (s[i] != ' ')
		{
			if (uutien(s[i]) == 0 )//&& s[i] != '(' && s[i] != ')')
				printf("%c", s[i]);
			else
			{
				if (s[i] == '(')
					push(s[i]);
				else
				{
					if (s[i] == ')')
					{
						char x;
						do{
							x = pop();
							if (x != '(')
								printf("%c", x);
						}while (s[i] != '(' && x != 0);
					}
					else
					{
						if (kt_rong() == 0)
							push(s[i]);
						else
						{
							char x;
							x = pop();
							if (uutien(s[i]) <= uutien(x) && x!='(' )
							{
								printf("%c", x);
							}
							else
							{
								push(x);
							}
							push(s[i]);
						}
					}
				}
			}
		}
	}
	while (kt_rong() == 1)
	{
		char x;
		x = pop();
		printf("%c", x);
	}
}

int main()
{
	setbuf(stdout, NULL);
	char s[100];
	printf("\nNhap vao 1 bieu thuc trung to:\n");
	fflush(stdin);
	gets(s);
	xuly(s);
	return 0;

}
