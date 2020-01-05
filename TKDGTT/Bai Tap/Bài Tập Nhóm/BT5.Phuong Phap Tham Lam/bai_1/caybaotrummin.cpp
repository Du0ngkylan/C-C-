//thuat toan tim cay bao trum min
#include"stdio.h"
#include"stdlib.h"
#include"conio.h"
#define hs 100
int m,n,dau[hs],cuoi[hs],v[hs],vd[hs],w[hs][hs];
//v[] de danh dau cung,vd[] de danh dau dinh da di qua
void khoidau()
{
	int i;
	for(i=1;i<=n;i++)
		vd[i]=0;
	for(i=1;i<=m;i++)
		v[i]=0;
}
void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
void nhap()
{
	int i,j,k,l;
	FILE *f;
	char s[200];
	f=fopen("dothi.txt","r");
	if(!f)
	{
		printf("loi mo tep");	getch();	exit(0);
	}
	fscanf(f,"%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		fscanf(f,"%d%d%d",&j,&k,&l);
		dau[i]=j;
		cuoi[i]=k;
		w[dau[i]][cuoi[i]]=l;
		fgets(s,100,f);
	}
	fclose(f);
	for(k=1;k<m;k++)
    {
		for(l=k+1;l<=m;l++)
		{
			if((w[dau[k]][cuoi[k]])>(w[dau[l]][cuoi[l]]))
			{
				swap(&dau[k],&dau[l]);                   
				swap(&cuoi[k],&cuoi[l]);
			}
		}
    }
}
void caybt()
{
	v[1]=1;
	vd[dau[1]]=vd[cuoi[1]]=1;
	int tiep=1,i;
	while(tiep)
	{
		tiep=0;
		for(i=1;i<=m;i++)
			if(v[i]==0)
				if((vd[dau[i]]+vd[cuoi[i]])==1)
				{
					v[i]=1;
					vd[dau[i]]=1;
					vd[cuoi[i]]=1;
					tiep=1;
				}
	}
}
void incay()
{
	int i;
	for(i=1;i<=n;i++)
		if(vd[i]==0)
		{
			printf("\ndo thi khong co cay bao trum");	getch();	exit(0);
		}
	printf("do thi co cay bao trum min la:\n");
	for(i=1;i<=m;i++)
		if(v[i])
			printf("%d->%d--%d\n",dau[i],cuoi[i],w[dau[i]][cuoi[i]]);
}
int main()
{
	nhap();
	khoidau();
	caybt();
	incay();
	getch();
}
//tim cay bao trum ngan nhat cua do thi co trong so
