/*
 * chuyen_trungto_hauto.c
 */

//bai dung

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct Node
{
	char s;
	//char s[20];
	struct Node *next;
}Node;

struct Node *stack=NULL;

//kiem tra stack rong
int isEmpty()
{
	if (stack == NULL)
		return 0;
	return 1;
}
//kiem tra day co can k

//dua 1 ptu vao stack

void push(char s)
{
	Node *node = (Node*)malloc(sizeof(Node));
	if (node != NULL)
	{	node->s = s;
		//strcpy(node->s, s);
		node->next = stack;
		stack = node;
	}
}
//dua 1 phan tu ra khoi stack
int pop()     //char
{
	if (stack != NULL)
	{
		Node *p;
		p = stack;char s;
		//char s[20];
		p = stack;s = p->s;
		//strcpy(s, p->s);
		//strcmp(p->s, s)==0;
		stack = p->next;
		free(p);
		return s;
	}
	return 0;
}
//do uu tien cho cac phep toan

int uutien(char c)
{
	if (c == '+' || c == '-')
		return 1;
	else
		if (c == '*' || c == '/')
			return 2;
		else
			return 0;
}
//kiem tra toan tu

int kt_toantu(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return 1;
	else
		return 0;
}
//ham

void caidat(char s[])
{
	int i;
	int n = strlen(s);
	for (i=0; i<n; i++)//can xem dau tien no co la khong trang hay khong
	{
		if (uutien(s[i]) == 0 && s[i] != '(' && s[i] != ')')//kt_toantu cung dc
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
					do
					{
						x = pop();
						if (x != '(')
						 printf("%c", x);
					}while (x != '(');//&& x != 0
					/*while (x != '(')
					{
						x = pop();
						if (x != '(')
							printf("%c", x);
					}*/
				}
				else
				{
					if (isEmpty() == 0)
						push(s[i]);
					else
					{
						char x = pop();
						if (x != '(' && uutien(s[i]) <= uutien(x))
							printf("%c", x);
						else
							push(x);
						push(s[i]);
					}
				}
			}
		}
	}
	while (isEmpty() == 1)
	{
		char x = pop();
		printf("%c", x);
	}
}

void tinhtoan(char s[])
{
	int i;
	for (i=0; i<strlen(n); i++)
	{
		if (s[i] != ' ')
		{
			if (uutien(s[i] == 0 && s[i] != '(' && s[i] != ')'))
			{
				char c = s[i];
				int t = atoi(&c);
				push(t);
			}
			else
			{
				int t1 = pop();
				int t2 = pop();
				int kq;
				switch(s[i]){
				case '+':
					kq = t1+t2;
				case '-':
					kq = t2-t1;
				case '*':
					kq = t1*t2;
				case '/':
					kq = t1+t2;
				}
				push(kq);
			}
		}
	}
}
int main()
{
	setbuf(stdout,NULL);
	char s[100];
	printf("\nNhap vao 1 bieu thuc trung to:\n");
	fflush(stdin);
	gets(s);
	caidat(s);
	return 0;
}

