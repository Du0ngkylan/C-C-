#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
	char datum[20];
	struct node *next;
}node;
typedef struct Tree
{
	char datum[20];
	struct Tree *left;
	struct Tree *right;
}Tree;
void push(node **stack,char *datum)
{
	node *Node1=(node *)malloc(sizeof(node));
	strcpy(Node1->datum,datum);
	Node1->next=*stack;
	*stack=Node1;
}
char *pop(node **stack)
{
	if(*stack!=NULL){
		char datum[20];
		strcpy(datum,(*stack)->datum);
		node *p;p=*stack;
		*stack=p->next;
		free(p);
		return datum;
	}
	else return NULL;

}
node *create(char c[20]){
	node *q=(node *)malloc(sizeof(node));
	if(q!=NULL){
		strcpy(q->datum,c);
		q->next=NULL;
	}
	return q;
}
void enqueue(node **list,char c[20]){
	node *q=create(c);
	if(*list==NULL){
		*list=q;
	}
	else {
		node *p=*list;
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=q;
	}
}
int higherPrecedence(char *s)
{
	if((strcmp(s,"(")==0)||(strcmp(s,")")==0)||(strcmp(s,"+")==0)||(strcmp(s,"-")==0)||(strcmp(s,"*")==0)||(strcmp(s,"\\")==0))
	{
		if(strcmp(s,"(")==0)
			return 0;
		else{
			if((strcmp(s,"*")==0)||(strcmp(s,"\\")==0))
				return 3;
			else
				if(strcmp(s,")")==0)
					return 1;
				else
					return 2;
		}
	}
	else
		return -1;
}
node *infixToPostfix(node *inqueue)
{
	node *stack1=NULL,*stack2=NULL;
	char t[20];
	while(inqueue!=NULL)
	{
		if(higherPrecedence(inqueue->datum)>=0)
		{

			if(stack1!=NULL){
				if(higherPrecedence(inqueue->datum)>higherPrecedence(stack1->datum)||higherPrecedence(inqueue->datum)==0)
					push(&stack1,inqueue->datum);
				else
				{
					while(stack1!=NULL)
					{
						if(strcmp(stack1->datum,"(")&&strcmp(stack1->datum,")"))
						{
							strcpy(t,pop(&stack1));
							push(&stack2,t);
						}
						else
							pop(&stack1);
					}
					push(&stack1,inqueue->datum);
				}
			}
			else
				push(&stack1,inqueue->datum);
		}
		else
			push(&stack2,inqueue->datum);
		inqueue=inqueue->next;
	}
	while(stack1!=NULL)
	{
		if(strcmp(stack1->datum,"(")&&strcmp(stack1->datum,")"))
		{
			strcpy(t,pop(&stack1));
			push(&stack2,t);
		}
		else
			pop(&stack1);
	}
	return stack2;

}
Tree *createNode(char datum[20])
{
	Tree *node=(Tree *)malloc(sizeof(Tree));
	strcpy(node->datum,datum);
	node->left=NULL;
	node->right=NULL;
	return node;
}
void infixToTree(Tree **tree,node **stack,char x[20])
{
	if(*stack!=NULL)
	{
		strcpy(x,pop(&(*stack)));
		*tree=createNode(x);
		if(strcmp((*stack)->datum,"+")==0||strcmp((*stack)->datum,"-")==0||strcmp((*stack)->datum,"*")==0||strcmp((*stack)->datum,"\\")==0)
		{
			infixToTree(&(*tree)->right,&(*stack),x);
		}
		else
		{
			if((*tree)->right==NULL)
			{
				strcpy(x,pop(&(*stack)));
				(*tree)->right=createNode(x);
			}
			strcpy(x,pop(&(*stack)));
			(*tree)->left=createNode(x);
			infixToTree(&(*tree)->left->left,&(*stack),x);
		}
	}

}
void printlist(node *list)
{
	while(list!=NULL)
	{
		printf("%s ",list->datum);
		list=list->next;
	}
}
void visitTree(Tree *tree)
{
	printf("%s ",tree->datum);
}
void postOrder(Tree *tree)
{
	if(tree!=NULL)
	{
		postOrder(tree->left);
		postOrder(tree->right);
		visitTree(tree);
	}
}
node *stringToInQueue(char s[255])
{
	int i,j,k,l;
	char x[20],y[20];
	node *inqueue=NULL;
	for(i=0;i<strlen(s);i++)
	{
		if(i==0)j=0;
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='\\'||s[i]=='('||s[i]==')')
		{
			l=0;
			for(k=j;k<i;k++)
			{
				y[l]=s[k];
				l++;
			}
			y[l]='\0';
			if(i!=j)
				enqueue(&inqueue,y);
			x[0]=s[i];
			x[1]='\0';
			j=i+1;
			enqueue(&inqueue,x);
		}
		else
			if(i==strlen(s)-1)
			{
				l=0;
				for(k=j;k<i+1;k++)
				{
					x[l]=s[k];
					l++;
				}
				x[l]='\0';
				enqueue(&inqueue,x);
			}

	}
	return inqueue;
}
int main()
{
	setvbuf(stdout,NULL,_IONBF,0);
	node *queue=NULL,*stack=NULL;
	Tree *tree=NULL;char x[20],s[255];
	gets(s);
	queue=stringToInQueue(s);
	printf("queue:\n");
	printlist(queue);
	printf("\n");
	stack=infixToPostfix(queue);
	printf("stack:\n");
	printlist(stack);
	printf("\n");
	printf("tree:\n");
	infixToTree(&tree,&stack,x);
	postOrder(tree);
	return 0;
}

