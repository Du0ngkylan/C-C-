#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

void nhap(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\n a[%d] = ",i);
		scanf(" %d",&a[i]);
	}
}

void in(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\n a[%d] = %d ",i,a[i]);
	}
}

int max(int a,int b)
{
	if(a >= b) return a;
	else return b;
}

int min(int a,int b)
{
	if(a<=b) return a;
	else return b;
}

void maxmin(int a[],int L,int R ,int &Max,int &Min)
{
	int Max1, Max2, Min1, Min2;
	if((L+1)<=R)
	{
		maxmin(a,L,(L+R)/2,Max1,Min1);
		maxmin(a,(L+R)/2 +1,R,Max2,Min2);
		Max = max(Max1, Max2);
		Min = min(Min1, Min2);
	}
	else
	{
		if(a[L]<=a[R])
		{
	    	Max = a[R];
	    	Min = a[L];
	    }
	    else
	    {
			Max = a[L];
	    	Min = a[R];
		}
	}
}

int main()
{
	int a[100];
	int  Max, Min,n;
	printf("Nhap so phan tu cua day: n = ");
	scanf("%d",&n);
	nhap(a,n);
	printf("\nDay vua nhap vao la: ");
	in(a,n);
	maxmin(a,0,n-1,Max,Min);
	printf("\nPhan tu max cua day la: %d", Max);
	printf("\nPhan tu min cua day la: %d", Min);
	getch();
	return 0;
}

