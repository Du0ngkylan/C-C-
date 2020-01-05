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

void shiftElement(int *a, int i)
{
	int iValue = a[i];
	while ((i > 0) && (a[i-1]>iValue))
	{
		a[i] = a[i-1];
		i--;
	}
	a[i] = iValue;
}

void insertionSort(int *a, int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		if (a[i] < a[i-1])
		{
			shiftElement(a, i);
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
	insertionSort(a, n);
	printf("\nMang da sa[ xep la:\n");
	in_mang(a, n);
	return 0;
}



