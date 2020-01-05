#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define maxN   1000
#define maxK   1000

int a[maxN];
int f[maxK][maxK];
int n,k;

void doc_file()
{
	FILE *fi = fopen("SUBSEQ.INP","r");
	if(!fi)
	{
		printf("Loi mo tep");
		getch();
		exit(0);
	}
	fscanf(fi,"%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		fscanf(fi,"%d",&a[i]);
	}
	fclose(fi);
}

// Tinh x - y theo mod k
int Sub(int x, int y)
{
	int s;
	int tmp;
	tmp = (x-y)%k;
	if(tmp >= 0) s = tmp;
	else s = tmp + k;
	return s;
}

void Optimize()
{
	int i,t;
	// Khoi tao
	f[0][0] = 0;
	for(t=1;t<k;t++)
	{
		f[0][t] = maxK;
	}
	// Giai cong thuc truy hoi
	for(i = 1; i <= n; i++)
	{
		for(t = 0; t < k; t++)
		{
			// Tinh f[i][t]  =  min f[i-1][Sub(t,a[i])] + 1
			if(f[i-1][t] < f[i-1][Sub(t,a[i])] + 1)
			{
				f[i][t] = f[i-1][t];
			}
			else
			{
				f[i][t] = f[i-1][Sub(t,a[i])] + 1;
			}
		}
	}
}

void Result()
{
	int i, t;
	int SumAll, Sum;
	SumAll = 0;
	for(i=1;i<=n;i++) SumAll = SumAll + a[i];
	FILE *fo = fopen("SUBSEQ.OUT","w");
	// n - so phan tu bo di = so phan tu giu lai
	fprintf(fo,"%d",n-f[n][SumAll % k]);
	i = n;
	t = SumAll % k;
	Sum = 0;
	for(i=n;i>=1;i--)
	{
		if(f[i][t] == f[i-1][t])
		{
			fprintf(fo,"\na[%d] = %d",i,a[i]);
			Sum = Sum + a[i];
		}
		else
		{
			t = Sub(t,a[i]);
		}
	}
	fprintf(fo,"\nSum = %d",Sum);
	fclose(fo);
}

int main()
{
	doc_file();
	Optimize();
	printf("\nMo file SUBSEQ.OUT de xem kq\n");
	Result();
	getch();
	return 0;
}
