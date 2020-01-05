//tim to hop chap k cua n phan tu//
#include<stdio.h>
#include<conio.h>
int n, k, dd[100], x[100];
void nhap(int *n, int *k)
{
	printf("\nNhap vao so n = ");
	scanf("%d",n);
	printf("\nNhap vao so k = ");
	scanf("%d",k);
}

void in(int n, int *x)
{
	for(int i=1; i<=n; i++)	
		printf("%2d", *(x+i));
	printf("\n\n");
}

void Try(int i, int n, int k,int *x,int *dd)
{
	for(int j=i; j<= n-k+i;j++ )
		if(*(dd+j) == 0)
		{
			x[i] = j;
			*(dd+j) = 1;
			if(i==k)
				in(k,x);	
			else
			 Try(i+1,n,k,x,dd);
			*(dd+j) =0;
		}
}
int main()
{
	nhap(&n,&k);
	printf("\nTo hop chap %d cua %d phan tu la: \n\n",k,n);	
	Try(1,n,k,x,dd);
	getch();
	return 0;
}
