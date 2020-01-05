/*
 * snt_dsmn.c
 *
 *  Created on: Oct 10, 2012
 *      Author: NgoHuong
 */


/*
 * primenumbers.c
 *tao dsmn cac so nguyen to<=n
 *  inra danh sach cac so do
 *      dao nguoc danh sach
 *      giai phong bo nho
 */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int ktnt(int k)
{
	int i;
	if(k<2) return 0;
	for(i=2;i<k;i++)
		if(k%i==0) {
			return 0;
			break;
		}
	return 1;
}

struct Node
{
	int prime;
	struct Node *next;
};
struct Node* them(int n)
{
	int i;
	struct Node *list,*p;
	list=NULL;
	for(i=0;i<=n;i++)
	{
		if(ktnt(i))
		{
			p=(struct Node*)malloc(sizeof(struct Node));
			p->prime = i;
			p->next=list;
			list=p;
		}
	}
	return list;

}
struct Node* reserve(struct Node *list)
{
	struct Node *p,*last,*q;
	last=NULL;q=NULL;//co can q=NULL khong
	if(list==NULL) printf("danh sach rong");
	else
	{
		for(p=list;p!=NULL;p=p->next)
		{
			q=(struct Node*)malloc(sizeof(struct Node));
			q->prime = p->prime;
			q->next = last;
			last=q;
		}
		q=last;//  khong can
	}
	return q;//neu the chi can tr ve last la dc
}


void inds(struct Node *list)
{
	struct Node *p;
	if(list==NULL)
	{
		printf("danh sach rong");
		return;
	}
	for(p=list;p!=NULL;p=p->next)
		printf("%5d",p->prime);
}
int main()
{
	struct Node *p,*q;
	int n;
	setvbuf(stdout,NULL,_IONBF,0);
	printf("moi ban nhap n=");
	scanf("%d",&n);
	p=them(n);
	inds(p);
	printf("\nds dao nguoc la:\n");
	q=reserve(p);
	inds(q);
getch();
	return 0;
}














