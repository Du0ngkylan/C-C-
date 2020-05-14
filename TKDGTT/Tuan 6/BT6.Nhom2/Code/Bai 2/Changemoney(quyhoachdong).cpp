//XAY DUNG BAI TOAN DOI TIEN QUY HOACH DONG 
#include <stdio.h>
#include <conio.h>
#include  <stdlib.h>

void init(int **L, int n, int k)
{
	int i, j;
	for(i=0; i<=n; i++)
	{
		for(j=0; j<=k; j++)
		{
			L[i][j]=0;
		}
	}
}

void input(int *D, int n)
{
	int i;
	for(i=1; i<=n; i++)
	{
		printf("Menh gia loai tien %d D[%d] = ", i, i); scanf("%d", &D[i]);
	}
}

int min(int a, int b)
{
	return a<b?a:b;
}

void output(int **L, int n, int k)
{
	int i, j;
	for(i=0; i<=n; i++)
	{
		printf("\n");
		for(j=0; j<=k; j++)
		{
			printf("%10d", L[i][j]);
		}
	}
}

void changemoney(int **L, int *D, int n, int k)
{
	int i, j, p;
	for(j=0; j<=k; j++)
	{
		L[0][j] = 0xFFFF;
	}
	for(i=0; i<=n; i++)
	{
		L[i][0] = 0;
	}
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=k; j++)
		{
			p=0xFFFF;
			if(D[i]<=j)
			{
				p = L[i][j - D[i]] + 1;
			}
			L[i][j] = min(p, L[i-1][j]);
		}
	}
}


int main()
{
	int n, *D, k, i;//mang D la mang chua cac loai tien
	//k la gia tri tien muon doi
	int **L, *dd;//l la bang quy hoach dong trong do L[i][j] la gia tri nho nhat khi doi J dong ra i loai toan
	//mang dd danh dau cac loai tien da duoc dung de doi sang
	printf("Nhap vao so loai tien co the doi n = "); scanf("%d", &n);
	D=(int *)malloc((n+1)*sizeof(int));
	dd=(int *)malloc((n+1)*sizeof(int));
	input(D, n);
	printf("\nNhap vao gia tri tien muon doi : "); scanf("%d", &k);
	L=(int **)malloc((n+1)*sizeof(int *));
	for(i=0; i<=n; i++)
	{
		L[i]= (int *)malloc((k+1)*sizeof(int ));
	}
	init(L, n, k);
	changemoney(L, D, n, k);
	output(L, n, k);
	printf("\nNhin vao bang L ta thay so to tien it nhat khi doi %d dong sang la %d", k, L[n][k]);
	getch();
	return 0;
}
