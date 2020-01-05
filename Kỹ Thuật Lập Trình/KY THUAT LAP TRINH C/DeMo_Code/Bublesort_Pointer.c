/*Sap xep noi bot*/

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

void bubbleSort(int *a, int n)
{
	int i, j;
	for (i=0; i<n; i++)
	{
		for (j=n-1; j>i; j--)
		{
			if (*(a+j-1) > *(a+j))  //a[j-1] >a[j]
				swap((a+j-1), (a+j));  //&a[j-1], &a[j]
		}
	}
}

int main()
{
	int n, *a;
	setbuf(stdout, NULL);
	printf("\nNhap n= ");scanf("%d", &n);
	a = nhap_mang(n);
	printf("\nMang da nhap la:\n");
	in_mang(a, n);
	bubbleSort(a, n);
	printf("\nMang da sap xep la:\n");
	in_mang(a,n);
	return 0;

}
