#include<stdio.h>
#include<conio.h>
int n, x[100], dd[100];

void nhap(int *n)
{
	printf("\nNhap vao so n = ");
	scanf("%d",n);
}
void in(int n, int *x)
{
	for(int i=1; i<=n; i++)	
		printf("%2d", *(x+i));
	printf("\n\n");
}
void Try(int i, int n, int *dd, int *x)
{
	for(int j=1; j<= n; j++)
		{
			if(*(dd+j) == 0)
			{
				*(x+i) = j;		
				*(dd+j) = 1;
				if(i==n)
					in(n,x);
				else
					Try(i+1,n,dd,x);
					*(dd+j) = 0;						
		}
	}
}
int main()
{
	nhap(&n);
	printf("\nCac hoan vi cua %d phan tu la: \n",n);
	Try(1,n,dd,x);
	getch();
	return 0;
}
