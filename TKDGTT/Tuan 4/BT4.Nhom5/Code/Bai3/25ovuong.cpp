#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int dau[100], cuoi[100], n, m, dd[100], v[100];
//khoi tao cho mang danh dau cac dinh la chua xet
void khoitao(int n)
{
	int i;
	for(i=1; i<=n; i++)
	{
		dd[i]=0;
	}
}
//doc cac danh sach cung trong bai toan
void doctep()
{
	int i;
	FILE *f;
	f=fopen("25ovuong.inp", "r");
	if(!f)
	{
		puts("\nLoi mo tep");
		getch();
		exit(1);
	}
	fscanf(f, "%d %d", &n, &m);
	khoitao(n);
	for(i=1; i<=m; i++)
	{
		fscanf(f, "%d %d", &dau[i], &cuoi[i]);
	}
	fclose(f);
}
//in ra danh sach cung doc duoc tu tep
void indscung()
{
	int i;
	printf("\nSo dinh cua do thi la %d\nSo cung cua do thi la %d", n, m);
	printf("\nIn ra danh sach cung cua do thi la");
	for(i=1; i<=m; i++)
	{
		printf("\n%d--%d", dau[i], cuoi[i]);
	}
}
//kiem tra 2 dinh co ke nhau khong
int ke(int i, int j)
{
	int k;
	for(k=1; k<=m; k++)
	{
		if(dau[k]==i&&cuoi[k]==j||dau[k]==j&&cuoi[k]==i)
		{
			return 1;
		}
	}
	return 0;
}
//in ra duong di tu o 1 den 0 25
void induongdi(int k)
{
	int i;
	for(i=1; i<=k; i++)
	{
		printf("%d---", v[i]);
	}
	printf("\n");
}
//tim duong di tu o 1 den o 24 nhu bai toan tim chu trinh hamilton
void timcachve(int k)
{
	int i;
	if(k>n)
	{
		return ;
	}
	if(k==n&&v[k]==24)
	{
		induongdi(k);
		return ;
	}
	for(i=1; i<=n; i++)
	{
		if(dd[i]==0&&ke(v[k], i))
		{
			dd[i]=1;
			v[k+1]=i;
			timcachve(k+1);
			dd[i]=0;
		}
	}
	printf("\nKhong co duong di tu o 1 den o 24");
	getch();
	exit(0);
}
//ham chinh
int main()
{
	doctep();
	indscung();
	v[1]=1;
	dd[1]=1;
	timcachve(1);
	getch();
}
