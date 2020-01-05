/*
 * sinhvien_b2_lec3.c
 *
 *  Created on: Jan 2, 2013
 *      Author: NgoHuong
 *
 *cai dat 1 dsmn ten sv
 *tao 1 dsmn ten dc lay tu tep
 *sap xep ten,
 *nhap 1 ten chen thenm ten ma k lam mat tinh sx
 *nhap 1 ten tim kiem, va tra lai vi tri con tro
 *xoa ten dc nhap tu ban phim
 *ham giai phong
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node
{
	char name[30];
	struct Node *next;
}Node;

Node *addNode(Node *list, char ten[30])
{
	Node *p;
	p = (Node *)malloc(sizeof(Node));
	strcpy(p->name, ten);
	p->next = list;
	list = p;
	return list;
}

Node *readList(Node *list)
{
	FILE *f;
	f = fopen("sinhvien.txt", "r");
	if(!f)
	{
		printf("Loi mo tep!!");
		exit(0);
	}
	char ten[30];
	int i, n;
	fscanf(f, "%d", &n);
	for (i=0; i<n; i++)
	{
		fgets(ten, 30, f);
		/*if (ten[strlen(ten) - 1] == '\n')
			ten[strlen(ten)-1] = '\0';//seee*/
		ten[strlen(ten)-1] = '\0';
		list = addNode(list, ten);
	}
	fclose(f);
	return list;
}

void sort(Node *list)
{
	Node *p, *q;
	if (list == NULL)
	{
		printf("Danh sach rong");
		return;
	}
	for (p = list; p->next != NULL; p = p->next)
		for (q = p->next; q != NULL; q = q->next)
		{
			if (strcmp(p->name, q->name) >= 0)
			{
				char t[30];
				strcpy(t, p->name);
				strcpy(p->name, q->name);
				strcpy(q->name, t);
			}
		}
}

Node *insertList(Node *list)
{
	Node *p, *q;
	char ten[30];
	printf("\nNHap vao 1 ten can chen\n");
	fflush(stdin);
	gets(ten);
	q = (Node *)malloc(sizeof(Node));
	strcpy(q->name, ten);
	for (p=list; p != NULL; p=p->next)
	{
		if (strcmp(p->name, ten) > 0)
		{
			list = addNode(list, ten);
			return list;
		}
		if (strcmp(p->name, ten) <= 0 && strcmp(p->next->name, ten) > 0 )
		{
			q->next = p->next;
			p->next = q;
			return list;
		}
	}
	q->next = p->next;
	p->next = q;
	return list;
}

Node *find(Node *list)
{
	Node  *p;
	char ten[30];
	printf("\nNhap vao 1 ten can tim kiem: ");
	fflush(stdin);
	gets(ten);
	for (p = list; p != NULL; p=p->next)
	{
		if (strcmp(p->name, ten) == 0)
			return p;
	}
	return NULL;
}

Node *deleteList(Node *list)
{
	if (list == NULL)
	{
		printf("danh sach rong");
		exit(0);
	}
	//Node  *p;
	char ten[30];
	printf("\nNhap vao 1 ten can xoa: ");
	fflush(stdin);
	gets(ten);
	while (strcmp(list->name, ten) == 0)
	{
		Node *p;/////
		p = list;
		list = p->next;
		free(p);
	}
	Node *p;
	for (p=list; p->next != NULL;  )
	{
		if (strcmp(p->next->name, ten) == 0)
		{
			Node *q;
			q = p->next;
			p->next = q->next;
			free(q);
		}
		else
			p = p->next;
	}
	return list;
}
//huy danh sach

void freeList(Node *list)
{
	if (list == NULL)
	{
		printf("\nDanh sach da rong");
		return ;
	}
	while(list != NULL)
	{
		Node *p;
		p=list;
		list = p->next;
		free(p);
	}
}

void in_ds(Node *list)
{
	Node *p;
	if (list == NULL)
	{
		printf("\nDanh sach rong");
		return ;
	}
	for (p=list; p != NULL; p = p->next)
	{
		printf("%s\n", p->name);
	}
}

int main()
{
	setbuf(stdout, NULL);
	Node *list ;
	list = NULL;
	list = readList(list);
	printf("\nDanh sach ten sv co trong tep la:\n");
	in_ds(list);

	sort(list);
	printf("\nDanh sach da duoc sap xep la:\n");
	in_ds(list);

	list = insertList(list);
	printf("\nDanh sach sau khi them ten la:\n");
	in_ds(list);

	if (find(list) == NULL)
		printf("\nKhong co ten xuat hien trong tap");
	else
		printf("\nCo ten trong tep");

	list = deleteList(list);
	printf("\nDanh sach sau khi xoa la:\n");
	in_ds(list);

	return 0;

}
