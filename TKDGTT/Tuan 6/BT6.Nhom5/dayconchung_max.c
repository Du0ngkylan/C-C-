#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#define max 50
int x[max],y[max],c[max][max];
int i,j,m,n;
void dayconchung_max(int x[], int y[])
{
	for(i=0;i<=m;i++)
		c[i][0]=0;
	for(j=0;j<=n;j++)
		c[0][j]=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(x[i]==y[j]) c[i][j]=c[i-1][j-1]+1;
			else
				if(c[i][j-1]>c[i-1][j]) c[i][j]=c[i][j-1];
					else c[i][j]=c[i-1][j];
}
void print()
{
	i=m;
	j=n;
	while((i>0)&&(j>0))
		if(x[i]==y[j])
		{
			printf("%4d", x[i]);
			i--;
			j--;
		}
		else
		{
			if(c[i][j]==c[i][j-1]) j--;
			if(c[i][j]==c[i-1][j]) i--;
		}
}
void nhap()
{ 
	printf("Nhap so phan tu cua day thu nhat:\t");
	scanf("%d", &m);
	for(j=1;j<=m;j++)
	{
		printf("x[%d]=",j);
		scanf("%d", &x[j]);
	}
	printf("Nhap so phan tu cua day thu hai:\t");
	scanf("%d", &n);
	for(j=1;j<=n;j++)
	{
		printf("y[%d]=",j);
		scanf("%d", &y[j]);
	}
}
int main()
{
	nhap();
	printf("day con chung day nhat la:\n");
	dayconchung_max(x,y);
	print();
	getch();
	return 0;
}

		
