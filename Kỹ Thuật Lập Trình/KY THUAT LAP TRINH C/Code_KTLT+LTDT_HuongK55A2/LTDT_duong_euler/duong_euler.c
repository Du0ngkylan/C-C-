/*
 * duong_euler.c
 *
 *  Created on: Dec 21, 2012
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int dau[50],cuoi[50],b[50],n,m,v[50],d[50];
void thongbao(char *s)
{
	puts(s);
	exit(0);
}
void doctep()
{
	FILE *f;
	int i,j,k;
	f=fopen("dulieu.txt","r");
	if(!f)thongbao("loi doc tep");
	fscanf(f,"%d%d",&n,&m);
	for(k=1;k<=m;k++)
	{
		dau[k]=0;
		cuoi[k]=0;
	}
	for(k=1;k<=m;k++)
	{
		fscanf(f,"%d%d",&i,&j);
		dau[k]=i;
		cuoi[k]=j;
	}
	fclose(f);
	printf("ok");
}
void khoidau()
{
	int i;
	for(i=1;i<=m;i++)
		b[i]=1;
}
int timxp()
{
	int i;
	for(i=1;i<=n;i++)
		d[i]=0;
	for(i=1;i<=m;i++)
	{
		d[dau[i]]++;
		d[cuoi[i]]--;
	}
	for(i=1;i<=n;i++)
		if(d[i]==1) return i;
	return 0;
}
void inkq()
{
	int i;
	for(i=1;i<=m+1;i++)
		printf("%5d",v[i]);
	puts("");
	exit(0);
}
void dequy(int k)
{
	int i;
	if(k>m+1) return;
	if(k==m+1)
		inkq();
	for(i=1;i<=m;i++)
	{
		if(b[i]==1 && v[k]==dau[i])
		{
			//b[i]=0;
			v[k+1]=cuoi[i];b[i]=0;
			dequy(k+1);
			b[i]=1;
		}
	}
}
int main()
{
	setvbuf(stdout,NULL,_IONBF,0);
	doctep();
	int x0=timxp();
	if (x0 == 0)
	{
		printf("\nKhong co duong euler");
		exit(0);
	}
	printf("\ndinh xuat phat la x0  = %d\n",x0);
	khoidau();
	v[1]=x0;
	dequy(1);
	puts("\nkhong co duong Euler");
	return 0;
}



