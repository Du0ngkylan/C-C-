/*
 * binarySort.c
 *
 *  Created on: Sep 30, 2012
 *      Author: NgoHuong
 */
#include <stdlib.h>
#include <stdio.h>

int *nhap_mang(int n)
{
	int i, *a;
	a = (int *)malloc(n*sizeof(int));
	for (i=0; i<n; i++)
	{
		printf("\nNhap a[%d]= ", i+1);
		scanf("%d", (a+i));
	}
	return a;
}

void in_mang(int *a, int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		printf("%5d", *(a+i));
	}
}

int *binarySearch(int *a, int n, int value)
{
	int i, j, m;
	i = 0; j = n-1;
	while (i <= j)
	{
		m = (i+j)/2;
		if (a[m] == value)
		{
			return (a+m);
		}
		else
		{
			if (a[m] < value)
				i = (m+1);
			else
				j = (m-1);
		}
	}
	return NULL;
}

int main()
{
	setbuf(stdout, NULL);
	int n, *a, value;
	printf("Nhap n= ");scanf("%d", &n);
	a = nhap_mang(n);
	printf("\nMang da nhap la:\n");
	in_mang(a, n);
	printf("\nNhap value= ");scanf("%d", &value);
	if (binarySearch(a, n, value) != NULL)
	{
		printf("\nGia tri %d co xuat hien trong day", *binarySearch(a, n, value));
	}
	else
	{
		printf("\nKhong co gia tri %d trong day", value);
	}
}
/*muon in ra vi tri cua gia tri tim thay thi
 * int *p;
 * p = binarSearch(a, n, value);
 * if(p!=NULL)in co %d trong mang o vi tri %d, *p,(p-a)
 * else in ra khong co
 */

