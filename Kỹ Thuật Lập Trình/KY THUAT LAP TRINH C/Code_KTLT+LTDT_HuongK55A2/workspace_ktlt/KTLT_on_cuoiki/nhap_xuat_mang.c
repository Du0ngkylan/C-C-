/*
 * nhap_xuat_mang.c
 *
 *  Created on: Dec 31, 2012
 *      Author: NgoHuong
 */

#include <stdio.h>
#include <stdlib.h>

int *nhap_mang(int n)
{
	int *a;
	a = (int*)malloc(n*sizeof(int));
	int i;
	for (i=0; i<n; i++)
	{
		printf("\nNhap phan tu thu %d", i+1);
		scanf("%d", (a+i));
	}
	return a;
}

void in_mang(int *a, int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		printf("%d\t", *(a+i));
	}
}
//swap

void swap(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
//sap xep

void sap_xep_chon(int *a, int n)
{
	int i, j;
	for (i=0; i<n-1; i++)
	{
		for (j=i+1; j<n; j++)
		{
			if (*(a+i) > *(a+j))
				swap((a+i), (a+j));
		}
	}
}

//tim kiem

int *tim_kiem(int *a, int n, int x)
{
	int i;
	for (i=0; i<n; i++)
	{
		if (*(a+i) == x)
			return (a+i);
	}
	return NULL;
}

int main()
{
	setbuf(stdout, NULL);
	int *a, n;
	printf("\nNhap n= ");
	scanf("%d", &n);
	a = nhap_mang(n);
	printf("\nMang da nhap la:\n");
	in_mang(a, n);
	int x;
	printf("\nNhap x= ");
	scanf("%d", &x);
	sap_xep_chon(a, n);
	printf("\nMang sau khi da sap xep la:\n");
	in_mang(a, n);
	if (tim_kiem(a, n, x) != NULL)
	{
		printf("\nCo x trong mang");
	}
	else
		printf("\nKhong co x trong mang");
	return 0;
}
