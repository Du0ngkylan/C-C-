/*
 * caybaotrum.c
 *
 *  Created on: Jan 3, 2013
 *      Author: NgoHuong
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int dau[50],cuoi[50],n,m,v[50],vc[50];
/*void thongbao(char *s)
{
	puts(s);
	exit(0);
}*/
void doctep()
{
	FILE *f;
	int i,j,k;
	f=fopen("dulieu.txt","r");
	if(!f)
	{
		printf("loi doc tep");
		exit(0);
	}
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
}

void tim()
{
	int i,tiep,dem;
	for(i=1; i<=m; i++)
		vc[i]=0;
	for(i=1; i<=n; i++)
		v[i]=0;

	vc[1]=1;
	v[dau[1]]=v[cuoi[1]]=1;
	tiep=1;
	dem=1;

	while(tiep)
	{
		tiep=0;
		for(i=1;i<=m;i++)
			if(v[dau[i]]+v[cuoi[i]]==1)
			{
				vc[i]=1;
				v[dau[i]]=v[cuoi[i]]=1;
				dem++;
				tiep=1;
				break;
			}
	}
	if(dem!=n-1) printf("do thi khong lien thong");
	else
	{
		for(i=1;i<=m;i++)
			if(vc[i]>0)
			{
				printf("%d\t%d\n",dau[i],cuoi[i]);
			}
	}
}
int main()
{
	setvbuf(stdout,NULL,_IONBF,0);
	doctep();
	tim();
	return 0;
}



