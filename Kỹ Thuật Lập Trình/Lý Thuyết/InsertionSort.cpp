#include<stdio.h>
#include<conio.h>

void in(int a[], int n)
{
	for(int i=0; i<n; i++)
		printf("%5d", a[i]);	
	printf("\n");
}

void shiftElement(int a[], int i) 
{
	int iValue = a[i];
	while ((i > 0) && (a[i-1] > iValue)) 
	{
		a[i] = a[i-1];
		i--;
	}
	a[i] = iValue;
}

void insertionSort(int a[], int n) 
{
	int i;
	for (i = 1; i < n; i++) 
	{
		if (a[i] < a[i-1]) 
		{
			shiftElement(a, i);
		}
	in(a,n);
	}
	in(a,n);
}


int main()
{
	int a[100], n;
	printf("n = ");
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	
	insertionSort(a,n);
	getch();
	return 0;	
}
