/*
 * bai1_sinhvien.c
 *
 *  Created on: Oct 29, 2012
 *      Author: NgoHuong
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sinhvien
{
	char name[30];
	float tb;
	struct sinhvien *next;
}sinhvien;

sinhvien *add(sinhvien *list, char ten[30], float tb)
{
	sinhvien *p;
	p = (sinhvien *)malloc(1*sizeof (sinhvien));
	strcpy(p->name, ten);
	p->tb = tb;
	p->next = list;
	list = p;
	return list;
}

sinhvien *createList(sinhvien *list, int n)
{
	int i;//n nhap o main
	char ten[30];
	float tb;
	//sinhvien *p;
	for (i=0; i<n; i++)
	{
		printf("\nNhap sinh vien thu: %d", i+1);
		printf("\nTen: ");
		fflush(stdin);
		gets(ten);
		printf("\nDiem TB: ");
		scanf("%f", &tb);
		fflush(stdin);
		list = add(list, ten, tb);
	}
	return list;
}

sinhvien *searchName(sinhvien *list, char ten[30])
{
	if (list == NULL)
	{
		puts("Danh sach rong");
		return NULL;
	}
	sinhvien *p;
	for (p=list; p!=NULL; p=p->next)
	{
		if (strcmp(p->name, ten) == 0)
		{
			return p;
		}
	}
	return NULL;
}

sinhvien *addEnd(sinhvien *list, char ten[30], float tb)
{
	sinhvien *p;

	for (p=list; p->next!=NULL; )
	{
		p=p->next;
	}
	sinhvien *q;
	q = (sinhvien*)malloc(sizeof(sinhvien));
	strcpy(q->name,ten);
	q->tb = tb ;
	q->next = NULL;
	p->next = q;
	return list;
}
void in_ds(sinhvien *list)
{
	if (list == NULL)
	{
		puts("Danh sach rong");
		return ;
	}
	sinhvien *p;
	for (p=list; p != NULL; p=p->next)
	{
		printf("%s\t%f\n", p->name, p->tb);
	}
}

int main()
{
	setbuf(stdout, NULL);
	int n;
	printf("\nNhap so sinh vien:");
	scanf("%d", &n);
	sinhvien *list, *p;
	list = NULL;
	list = createList(list, n);
	printf("\nDanh sach ten sinh vien nhap tu ban phim la:\n");
	in_ds(list);
	//float tb;
	p = searchName(list, "Nam");
	if (p!=NULL)
	{
		printf("\nCo ten trong danh sach\n");
		(p->tb) += ((p->tb)*(0.1));
	}
	else
	{
		printf("\nKhong co ten\n");
		list = addEnd(list, "Nam", 0.0);

		//doan nay no them vao dau
	}
	printf("\nDanh sach sau khi ...la:\n");
	in_ds(list);
	return 0;
}
