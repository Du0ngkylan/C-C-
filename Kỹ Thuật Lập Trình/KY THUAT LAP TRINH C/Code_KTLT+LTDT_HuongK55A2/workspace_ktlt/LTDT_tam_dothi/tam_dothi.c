/*
 * tam_dothi.c
 *
 *  Created on: Jan 4, 2013
 *      Author: NgoHuong
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[50][50],d[50][50],maxd[50],n,m;
//maxd[] luu lai  gia tri  lon nhat cua duong di ngan nhat tu i den j

void doctep()
{
	int i,j,k,t;
	FILE *f;
	f=fopen("dulieu.txt","r");
	if(!f)
	{
		printf("loi");
		exit(0);
	}
	fscanf(f,"%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			a[i][j]=0;
			d[i][j]=-1;
		}
	for(k=1;k<=m;k++)
	{
		fscanf(f,"%d%d%d",&i,&j,&t);
		a[i][j]=1;
		d[i][j]=t;
		d[j][i]=t;//do do thi nhap vao la do thi vo huong
	}
	fclose(f);
}
void minway()
{
	int i,j,k;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(i!=j)
				{
					if(d[i][k]>=0 && d[k][j]>=0)
					{
						if(d[i][j]<0 || d[i][j]>d[i][k]+d[k][j])
						{
							d[i][j]=d[i][k]+d[k][j];
						}
					}

				}
}
void maxhang()
{
	int i,s,j;
	for(i=1;i<=n;i++)
	{
		s=d[i][1];
		for(j=2;j<=n;j++)
			if(s<d[i][j]) s=d[i][j];
		maxd[i]=s;
	}
}
void tam()
{
	int i,s,t;
	s=maxd[1];t=1;
	for(i=2;i<=n;i++)
		if(s>maxd[i])
		{
			t=i;
			s=maxd[i];
		}
	printf("\ntam cua do thi la:%d",t);
	printf("\nban kinh cua do thi la:%d",s);
}
int main()
{
	setvbuf(stdout,NULL,_IONBF,0);
	doctep();
	minway();
	maxhang();
	tam();
	return 0;
}
