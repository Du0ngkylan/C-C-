/*
 * tan_so_xh_word.c
 *
 *  Created on: Oct 27, 2012
 *      Author: NgoHuong
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node
{
	char words[30];
	int freq;
	struct Node *next;
}Node;

Node *addNode(Node *list, char s[30], int freq)// khooit tao list = null o main
{
	Node *p;
	p = (Node*)malloc(1*sizeof(Node));
	strcpy(p->words, s);
	p->freq = freq;
	p->next = list;
	list=p;
	return list;
}

Node *dl(Node *list)
{
	FILE *f;
	f = fopen("englishWords.txt", "r");
	if (f == NULL)
	{
		puts("Loi mo tep");
		exit(0);
	}
	Node *p;
	char s[30];int freq;
	//int (p->freq) = 1;
	//fscanf(f, "%s", s);
	//strcmp(list->words, s);
	while (!feof(f))
	{
		fscanf(f, "%s", s);
		for (p=list; p!=NULL; p=p->next)
		{
			if (strcmp(p->words, s) == 0)
			{
				p->freq ++;
				//list = addNode(list, s, freq);
			}
			else
			{
				Node *q;
				q = (Node *)malloc(1*sizeof(Node));
				strcpy(q->words, s);
				q->freq = 1;q->next = list;
				list = q;
				//return list;
			}
		}
	}
	fclose(f);
	return list;
}

void in_ds(Node *list)
{
	if (list == NULL)
	{
		puts("Danh sach rong");
		exit(0);
	}
	Node *p;
	for (p=list; p!=NULL; p=p->next)
	{
		printf("%s\t%d", p->words, p->freq);
	}
}

void sortList(Node *list)
{
	Node *p, *q;
	if (list == NULL)
	{
		printf("Danh sach rong");
		exit(0);
	}
	for (p=list; p->next!=NULL; p=p->next)
	{
		for (q=p->next; q != NULL; q=q->next)
		{
			if(strcmp(p->words, q->words) > 0)
			{
				char t[30];
				strcpy(t,p->words);
				strcpy(p->words, q->words);
				strcpy(q->words, t);
			}
		}
	}
}

int main()
{
	setbuf(stdout, NULL);
	Node *list, *p;
	list = NULL;
	p = dl(list);
	printf("\nin\n");
	in_ds(p);
	printf("\ndanh sach da sap xep la:");
	sortList(p);
	in_ds(p);
	return 0;
}
