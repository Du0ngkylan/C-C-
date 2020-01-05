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

void selectionSort_first(int *a, int n)
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

int main()
{
	setbuf(stdout, NULL);
	int n, *a;
	printf("\nNhap n= ");scanf("%d", &n);
	a = nhap_mang(n);
	printf("\nMang da nhap la:\n");
	in_mang(a, n);
	selectionSort_first(a, n);
	printf("\nMang da sap xep la:\n");
	in_mang(a, n);
	return 0;
}
