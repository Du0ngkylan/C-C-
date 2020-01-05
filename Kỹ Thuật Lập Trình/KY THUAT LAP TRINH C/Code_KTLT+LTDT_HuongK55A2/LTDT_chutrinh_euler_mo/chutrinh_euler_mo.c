/*
 * chutrinhEuler.c
 *
 *  Created on: Dec 1, 2012
 *      Author: HongMo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int dau[50],cuoi[50],b[50],n,m,v[50];
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
void inkq()
{
	int i;
	for(i=1;i<=m+1;i++)
		printf("%5d",v[i]);
	puts("");
	//exit(0);
}
void dequy(int k)
{
	int i;
	if(k>m+1) return;
	if(k==m+1 && v[k]==v[1])
	{
		inkq();
		exit(0);
	}
	for(i=1;i<=m;i++)
	{
		if(b[i]==1 && v[k]==dau[i])
		{
			b[i]=0;
			v[k+1]=cuoi[i];
			dequy(k+1);
			b[i]=1;
		}
	}
}
int main()
{
	setvbuf(stdout,NULL,_IONBF,0);
	doctep();
	khoidau();
	v[1]=1;
	dequy(1);
	puts("\nkhong co chu trinh Euler");
	return 0;
}


