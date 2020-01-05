/*
 * bai2.c
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
	float dtb;
	struct sinhvien *next;
}sinhvien;

sinhvien *add(sinhvien *list, char ten[30], float dtb)
{
	sinhvien *p;
	p = (sinhvien *)malloc(sizeof(sinhvien));
	strcpy(p->name, ten);
	p->dtb = dtb;
	p->next = list;
	list = p;
	return list;
}

sinhvien *read(sinhvien *list)
{
	FILE *f;
	f = fopen("dulieusv.txt", "r");
	if (!f)
	{
		puts("Loi mo tep");
		exit(0);
	}
	int i, n;
	char ten[30];
	int dtoan, dtin;
	float dtb;
	fscanf(f, "\n%d\n", &n);
	//fgets(ten, 30, f);
	for (i=0; i<n; i++)
	{
		//printf("\nSinh vien thu: %d", i+1);
		fgets(ten, 30, f);
		if (ten[strlen(ten)-1] == '\n')
			ten[strlen(ten)-1] = '\0';
		fscanf(f, "%d\n", &dtoan);
		fscanf(f, "%d\n", &dtin);
		dtb = (float)(dtoan+dtin)/2;
		list = add(list, ten, dtb);
	}
	fclose(f);
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
	//char ten[30];
	//printf("\nNhap vao ten can tim: ");
	//gets(ten);
	for (p=list ;p!=NULL; p=p->next)
	{
		if (strcmp(p->name, ten) == 0)
		{
			return p;
		}
	}
	return NULL;
}

sinhvien *addEnd(sinhvien *list, char ten[30], float dtb)
{
	sinhvien *p;
	for (p=list; p->next!= NULL; p=p->next);
	sinhvien *q;
	q = (sinhvien *)malloc(sizeof(sinhvien));
	strcpy(q->name, ten);
	q->dtb = dtb;
	q->next = NULL;
	p->next = q;
	return list;
}

sinhvien *deleteName(sinhvien *list)
{
	if (list == NULL)
	{
		puts("Danh sach rong");
		return list;
	}
	sinhvien *p;
	float tb = 5.0;
	while(list->dtb < tb)
	{
		p = list;
		list = list->next;
		free(p);
	}
	for (p=list; p->next!=NULL; )
	{
		if ( (p->next->dtb) < tb)
		{
			sinhvien *q;
			q = p->next;
			p->next = p->next->next;
			free(q);
		}
		else
		{
			p=p->next;
		}
	}
	return list;
}

/*void freeList(sinhvien *list)
{
	if (list == NULL)
	{
		puts ("Danh sach rong");
		return;
	}
	while (p != NULL)
	{

	}
}*/
void in_ds(sinhvien *list)
{
	if (list == NULL)
	{
		puts("Danh sach rong");
		return;
	}
	sinhvien *p;
	for (p=list; p != NULL; p=p->next)
	{
		printf("%20s%6.2f\n", p->name, p->dtb);
	}
}

sinhvien *freeList(sinhvien *list)
{
	if (list == NULL)
	{
		puts("Danh sach rong!!!");
		return NULL;
	}
	sinhvien *p = list;
	while(p != NULL)//for (p=list; p!=NULL; p=p->next){sinhvien *q;q=p;free(q);
	{
		sinhvien *q;
		q = p;
		p=p->next;
		free(q);
	}
	return NULL;
}
int main()
{
	setbuf(stdout, NULL);
	sinhvien *list, *p;
	list = NULL;
	list = read(list);
	printf("\nDanh sach co trong file la:\n");
	in_ds(list);
	char ten[30];
	printf("\nNhap vao ten can tim: ");
	fflush(stdin);
	gets(ten);
	p = searchName(list, ten);
	//char ten[30];
	if (p != NULL)
	{
		printf("\nCo xuat hien ten trong danh sach\n");
		p->dtb = (p->dtb) + 1.0;
	}
	else
	{
		printf("\nco xuat hien ten trong danh sach\n");
		list = addEnd(list, ten, 5);
	}
	in_ds(list);
	list = deleteName(list);
	printf("\nDanh sach sau khi xoa la:\n");
	in_ds(list);
	list = freeList(list);
	printf("\nsau khi xoa danh sach la:\n");
	in_ds(list);
	return 0;
}
