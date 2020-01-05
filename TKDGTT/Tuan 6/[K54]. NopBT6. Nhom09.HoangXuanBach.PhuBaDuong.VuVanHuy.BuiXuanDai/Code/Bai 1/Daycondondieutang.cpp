#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void input(int *a, int n)
{
	int i;
	printf("Nhap vao day so:\n");
	for(i=1; i<=n; i++)
	{
		printf("a[%d] = ", i); scanf("%d", &a[i]);
	}
}
void output(int *a, int n)
{
	int i;
	printf("\nIn ra day so vua nhap la\n");
	for(i=1; i<=n; i++)
	{
		printf("%5d", a[i]);
	}
}
int dayconlonnhat(int *a, int *L, int n)
{
	int i, j;
	//L=(int *)malloc((n+1)*sizeof(int));
	for(i=0; i<=n; i++)
	{
		L[i]=0;
	}
	for(i=1; i<=n; i++)
	{
		L[i]=1;
		if(i>1)
		{
			for(j=1; j<i; j++)
			{
				if(a[i]>a[j]&&L[i]<L[j]+1)
				{
					L[i]=L[j]+1;
				}
			}
		}
	}
	j=L[1];
	for(i=2; i<=n; i++)
	{

		if(L[i]>j)
		{
			j=L[i];
		}
	}
	return j;
}

void Truyvet(int *a, int *L, int *dd, int n)
{
	int i, k, j;
	for(i=1; i<=n; i++)
	{
		dd[i]=0;
	}
	for(i=1; i<=n; i++)
	{
		if(L[i]==dayconlonnhat(a, L, n))
		{
			k=i;
			break;
		}
	}
	j=k;
	dd[j]=1;
	for(i=k-1; i>=1; i--)
	{
		if(a[i]<a[j]&&L[i]==L[j]-1)
		{
			dd[i]=1;
			j=i;
			printf("->%d", j);
		}
	}
	printf("\nDay con do la:\n");
	
	for(i=1; i<=n; i++)
	{
		if(dd[i]==1)
		{
			printf("%5d", a[i]);
		}
	}
}

int main()
{
	int *a, *L, *dd, n;//mang a chua day so dau vao
	//mang L chua chi so cua so a[i] thu tu nam trong day con
	//mang dd danh dau cac so nam trong day con dai nhat
	printf("\nNhap vao do dai ca day so n="); scanf("%d", &n);
	a=(int *)malloc((n+1)*sizeof(int));
	L=(int *)malloc((n+1)*sizeof(int));
	dd=(int *)malloc((n+1)*sizeof(int));
	input(a, n);
	output(a, n);
	printf("\nDo dai day con tang dai nhat la %d", dayconlonnhat(a, L, n));
	Truyvet(a, L, dd, n);
	getch();
}
