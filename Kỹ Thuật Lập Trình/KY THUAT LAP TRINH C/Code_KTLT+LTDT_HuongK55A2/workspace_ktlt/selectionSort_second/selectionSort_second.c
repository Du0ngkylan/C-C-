/*
 * selectionSort_second.c
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

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

/*ham tim vi tri j nho nhat*/

/*int Min(int *a, int n, int j)
{
	int i;
	int min = j;
	for (i=j+1; i<n; i++)
	{
		if (a[i] <a[min])
			min = i;
	}
	return min;
}

void selectionSort_second(int *a, int n)
{
	int i,  min;
	for (i=0; i<n; i++)
	{
		min = Min(a, n, i);
		swap(&a[i], &a[min]);
	}
}*/

void selectionSort_second(int *a, int n)
{
	int i, j, min;
	for (i=0; i<n-1; i++)
	{
		min = i;
		for(j=i+1; j<n; j++)
		{
			if (*(a+j) < *(a+min))
				min = j;

			swap((a+i), (a+min));
		}
	}
}

int main()
{
	setbuf(stdout, NULL);
	int n, *a;
	printf("\nNhap n= ");scanf("%d", &n);
	a = nhap_mang(n);
	printf("\nMang da nhap la:\n");
	in_mang(a, n);
	selectionSort_second(a, n);
	printf("\nMang da sap xep la:\n");
	in_mang(a, n);
	return 0;
}
