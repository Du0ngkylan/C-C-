/*
 * linearSearch.c
 *
 *  Created on: Sep 27, 2012
 *      Author: NgoHuong
 */

#include <stdio.h>
#include <stdlib.h>

int *nhap_mang(int n)
{
	int i, *a;
	a = (int *)malloc(sizeof(int));
	for (i=0; i<n; i++)
	{
		printf("\nNhap a[%d]= ", (i+1));
		scanf("%d", (a+i)); //&a[i]
	}
	return a;
}

void in_mang(int *a, int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		printf("%5d", *(a+i)); //a[i]
	}
}

// ham tim kiem ptu mang, tra ve dia chi mang hay la gia tri NULL

int* linearSearch(int *a, int n, int value)
{
	int i;
	for (i=0; i<n; i++)
	{
		if (*(a+i) == value)
			return (a+i);
	}
	return NULL;
}

int main()
{
	setbuf(stdout, NULL);
	int n, *a, x;
	printf("\nNhap n= ");scanf("%d", &n);
	a = nhap_mang(n);
	printf("\nMang da nhap la:\n");
	in_mang(a, n);
	printf("\nNhap vao ptu value= ");scanf("%d", &x);
	if (linearSearch(a, n, x) != NULL)
		printf("\nSo %d co trong day", *linearSearch(a, n, x));
	else
		printf("\nKhong tim thay so can tim");
	return 0;
}
