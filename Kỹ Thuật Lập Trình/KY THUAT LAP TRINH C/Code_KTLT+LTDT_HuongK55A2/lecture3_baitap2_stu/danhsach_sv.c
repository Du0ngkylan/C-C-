/*
 * danhsach_sv.c
 *
 *  Created on: Oct 16, 2012
 *      Author: NgoHuong
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node
{
	char name[30];
	struct Node *next;
}Node;

Node *addNode(Node *list, char ten[30])//list = NULL o main
{
	Node *p;
	p = (Node *)malloc(1*sizeof(Node));
	strcpy(p->name, ten);
	p->next = list;
	list = p;
	return list;
}

Node *readList(Node *list)
{
	FILE *f;
	f = fopen("d_s_s_v.txt", "r");
	if (!f)
	{
		puts("Loi mo tep");
		exit(0);
	}
	char ten[30];
	int i, n;
	fscanf(f, "%d ", &n);
	for (i=0; i<n; i++)
	{
		fgets(ten, 30, f);
		ten[strlen(ten)-1] = '\0' ;//// note note........
		list = addNode(list, ten);
	}
	fclose(f);
	return list;
}

void sortList(Node *list)
{
	Node *p, *q;
	if (list == NULL)
	{
		puts("Danh sach rong");
		exit(0);
	}
	for (p=list; p->next!=NULL; p=p->next)
	{
		for (q=p->next; q!=NULL; q=q->next)
		{
			if (strcmp(p->name, q->name) > 0)
			{
				char t[30];
				strcpy(t, p->name);
				strcpy(p->name, q->name);
				strcpy(q->name, t);
			}
		}
	}
}

Node *insertNode(Node *list)
{
	Node *p, *q;
	char ten[30];
	printf("\nNhap vao mot ten can them: ");
	fflush(stdin);
	gets(ten);
	q = (Node *)malloc(sizeof(Node));
	strcpy(q->name, ten);
	/*if (list == NULL)
	{
		//list = addNode(list, ten);
		list = p;
		return list;
	}*/
	for (p=list; p->next!=NULL; p=p->next)
	{
		if (strcmp(p->name, ten) > 0)
		{
			list = addNode(list, ten);
			return list;
		}
		if (strcmp(p->name, ten) <= 0 && strcmp(p->next->name, ten) >= 0)
		{
			q->next = p->next;
			p->next = q;
			return list;
		}
	}
	q->next = NULL;
	p->next = q;
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
		printf("%s\n", p->name);
	}
}

Node *search(Node *list)
{
	if (list == NULL)
	{
		puts("Danh sach rong");
		return NULL;
	}
	char ten[30];
	printf("\nNhap vao mot ten can tim: ");
	fflush(stdin);
	gets(ten);
	Node *p;
	for (p=list; p!=NULL; p=p->next)
	{
		if (strcmp(p->name, ten) == 0)
		{
			return p;
		}
	}
	return NULL;
}

Node *deleteNode(Node *list)
{
	if (list == NULL)
		{
		puts("Danh sach rong");
		return NULL ;
	}
	char ten[30];
	printf("\nNhap vao mot ten can xoa: ");
	fflush(stdin);
	gets(ten);
	while(strcmp(list->name,ten) == 0)
	{
		Node *p;
		p = list;
		list = list->next;//hay p->next;
		free(p);
	}
	Node *p;
	for (p=list; p->next!=NULL; )
	{
		if (strcmp(p->next->name, ten) == 0)
		{
			Node *q;
			q = p->next;
			p->next = q->next;
			free(q);
		}
		else
			p=p->next;
	}
	return list;
}

void freeList(Node *list)
{
	if (list == NULL)
	{
		puts("Danh sach rong");
		return;
	}
	while (list != NULL)
	{
		Node *p;
		p = list;
		list = list->next;
		free(p);
	}
}
int main()
{
	setbuf(stdout, NULL);
	Node *list, *p, *q, *k;
	list = NULL;
	p = readList(list);

	printf("\nDanh sach co trong tep dl:\n");
	in_ds(p);

	sortList(p);
	printf("\nDanh sach da sap xep la:\n");
	in_ds(p);

	q = insertNode(p);
	printf("\nDanh sach da them vao la:\n");
	in_ds(q);

	if (search(p)==NULL)
	{
		printf("\nKhong tim thay ten trong danh sach");
	}
	else
		printf("\nCo ten vua nhap trong danh sach");

	k = deleteNode(p);
	printf("\nDanh sach sau khi xoa la:\n");
	in_ds(k);

	return 0;
}


