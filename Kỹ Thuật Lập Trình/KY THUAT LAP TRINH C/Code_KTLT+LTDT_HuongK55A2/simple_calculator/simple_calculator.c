/*
 * simple_calculator.c
 *
 *  Created on: Oct 3, 2012
 *      Author: NgoHuong
 */

/*
 ============================================================================
 Name        : Simple_Calculator.c
 Author      : TIT10
 Version     : 1.0
 Copyright   : By TIT-PC
 Description : N/A
 ============================================================================
 */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX 100

//======================================//

typedef struct stack
{
	char item[MAX][10];
	int top ;
}stack;

typedef struct queue
{
	char list[MAX][10];
	int head , tail ;
}queue;

//========================================//

void S_init(stack *t)
{
    t->top = -1 ;
}

// Khoi tao hang doi rong

void Q_init(queue *q)
{
    q->head = 0;
    q->tail = 0;
}

// Kiem tra queue rong

int Q_isEmpty(queue *q)
{
	if(q->head == q->tail)
        return 1 ;
    else
        return 0 ;
}

// Kiem tra stack rong

int S_isEmpty(stack *t)
{
	if(t->top == -1)
		return 1 ;
	else
		return 0 ;
}

// Kiem tra stack day

int S_isFull(stack *t)
{
	return t->top == MAX-1 ? 1 : 0;
}



// Day 1 phan tu vao stack

void Push(stack *t , char *x)
{
	if (S_isFull(t))
	{
		printf("\n\n Stack is FULL !!!");
		exit(1);
	}
	t->top++;
	strcpy(t->item[t->top],x);
}

// Lay 1 phan tu va xoa pt khoi stack

int Pop(stack *t)
{
	if (S_isEmpty(t))
	{
		printf("\n\n Stack is EMPTY !!!");
		return 0;
	}
	t->top--;
	return 1;
}

// Copy phan tu dinh stack va tra ve vi tri

char* StackTop(stack *t)
{
	if (S_isEmpty(t))
	{
		printf("\n\n Stack is EMPTY !!!");
		exit(1);
	}
	return t->item[t->top];
}

// Kiem tra queue day

int Q_isFull(queue *q)
{
	if (q->head == -1 && q->tail == MAX-1) return 1;
    if (q->head > q->tail) return 1;
    return 0 ;
}
int EnQueue(queue *q, char *x)
{
    if (Q_isFull(q))
        return 0;
    strcpy(q->list[q->tail], x);
    q->tail++;
    if (q->tail == MAX)
        q->tail = 0;
    return 1;
}

// Trich va xoa 1 phan tu o day queue

char* DeQueue(queue *q)
{
    if (Q_isEmpty(q))
    {
        printf("\n\n Queue is EMPTY !");
        return NULL;
    }
    char *t= (char*)malloc(10*sizeof(char));
    strcpy(t , q->list[q->head]);
    q->head++;
    if (q->head == MAX) q->head = 0;
    return t;
}

// Kiem tra ki tu co phai la toan tu hay khong ?
int isParentheses(char *c)
{
	if(strcmp(c,"(")==0)
		return 1 ;
	if(strcmp(c,")")==0)
		return 2 ;
	else
		return 0 ;
}
int isOperator(char *c)
{
    if(strcmp(c,"+")==0 || strcmp(c,"-")==0|| strcmp(c,"*")==0|| strcmp(c,"/")==0 || strcmp(c,"%")==0 || strcmp(c,"^")==0)
        return 1;
    return 0;
}

// Gan do uu tien cho cac phep toan
int Precedent(char *c)
{
    if(strcmp(c,"+")==0|| strcmp(c,"-")==0)
        return 1;
    if(strcmp(c,"*")==0|| strcmp(c,"/")==0)
        return 2;
    if(strcmp(c,"%")==0|| strcmp(c,"^")==0)
        return 3;
    else
        return 0;
}

//Ham in queue

void DislayQueue(queue q)
{
	while(!Q_isEmpty(&q))
	{
		char *p = DeQueue(&q);
		printf("%s ",p);
	};
}
//Ham nhap xau vao queue
void EnterQueue(queue *inf)
{
	char str[100];
	printf("\n\n Nhap vao bieu thuc can tinh toan...");
	printf("\n\n Moi toan hang , toan tu cach nhau boi 1 khoang trang nhe :)");
	printf("\n\n Bat dau nao :");fflush(stdin);
	gets(str);
	int i , n = strlen(str);
	for(i=0;i<n;)
	{
		int j = i , k = 0 ;
		char q[10];
		while(str[j]!=' ')
		{
			q[k]=str[j];
			j++;k++;
		}
		q[k] ='\0';
		EnQueue(inf,q);
		i=j;
		while(str[i]==' ') i++;
	}
}

// Ham chuyen tu inf -> posf

void InfixToPostfix(queue inf,queue *q)
{
	stack t ;
	S_init(&t);
	while(!Q_isEmpty(&inf))
	{
		char *x = DeQueue(&inf) ;
		if(!isOperator(x) && isParentheses(x) == 0 )
			EnQueue(q,x);
		else
		{
			if(isParentheses(x)==1)
				Push(&t,x);
			else
			{
				if(isParentheses(x)==2)
				{
					while(isParentheses(StackTop(&t))!= 1)
					{
						EnQueue(q,StackTop(&t));
						Pop(&t);
					}
					Pop(&t);
				}
				else
				{
					while(!S_isEmpty(&t))
					{
						if(Precedent(x) <= Precedent(StackTop(&t)))
						{
							EnQueue(q,StackTop(&t));
							Pop(&t);
						}
						else
							break ;
					}
					Push(&t,x);
				}
			}
		}
	}

	while(!S_isEmpty(&t))
	{
		EnQueue(q,StackTop(&t));
		Pop(&t);
	}
	DislayQueue(*q);
}

//Ham tinh gia tri cua 2 so
float count(float a , float b , char *c)
{
	if(strcmp(c,"+")==0) return a + b ;
	if(strcmp(c,"-")==0) return a - b ;
	if(strcmp(c,"*")==0) return a * b ;
	if(strcmp(c,"/")==0) return a / b ;
	if(strcmp(c,"^")==0) return pow(a,b) ;
	if(strcmp(c,"%")==0) return (int)a % (int)b ;
	else return 0 ;
}
// Ham tinh bieu thuc hau to :
float Calculator(queue *pof)
{
	stack t ;
	S_init(&t);
	while(!Q_isEmpty(pof))
	{
		char *x = DeQueue(pof);
		if(!isOperator(x))
			Push(&t,x);
		else
		{
			float a = atof(StackTop(&t));
			Pop(&t);
			float b = atof(StackTop(&t));
			Pop(&t);
			char y[10] ;
			snprintf(y,9,"%f",count(b,a,x));
			Push(&t,y);
		}
	}
	return atof(StackTop(&t));
}
int main(void)
{
	setvbuf(stdout,NULL,_IONBF,0);
	queue pof , inf ;
	Q_init(&pof);
	Q_init(&inf);
	EnterQueue(&inf);
	printf("\n Bieu thuc hau to la :");
	InfixToPostfix(inf,&pof);
	printf("\n\n Gia tri cua bieu thuc : ");
	DislayQueue(inf);
	printf(" = %.3f ",Calculator(&pof));
	printf("\n\n Press anykey to exit...");
	exit(0);
}



