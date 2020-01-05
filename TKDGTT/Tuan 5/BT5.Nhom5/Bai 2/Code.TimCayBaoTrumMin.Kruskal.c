//thuat toan tim cay bao trum bang thuat toan kruskal
#include"stdio.h"
#include"stdlib.h"
#include"conio.h"
#define hs 100
int m,n,dau[hs],cuoi[hs],v[hs],vd[hs],w[hs][hs],ts[hs];
//v[] de danh dau cung,vd[] de danh dau dinh da di qua
//m=so canh
//n=so dinh
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
	f=fopen("dothi.dat","r");
	if(!f)
	{
		printf("loi mo tep");	getch();	exit(0);
	}
	fscanf(f,"%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		fscanf(f,"%d %d %d",&dau[i],&cuoi[i],&ts[i]);
		
	}
	fclose(f);
	printf("Do thi ban dau:\n");
	for(i=1;i<=m;i++)
	                 printf("%d->%d--%d\n",dau[i],cuoi[i],ts[i]);
	for(k=1;k<m;k++)
    {
		for(l=k+1;l<=m;l++)
		{
			if((ts[k]>ts[l]))
			{
                swap(&ts[k],&ts[l]);                                        
				swap(&dau[k],&dau[l]);
				swap(&cuoi[k],&cuoi[l]);				
				
			}
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
			printf("%d->%d--%d\n",dau[i],cuoi[i],ts[i]);
}
void caybt()
{
	v[1]=1;
	vd[dau[1]]=vd[cuoi[1]]=1;
	int k=0,i;
	while(k<n-1)
	{
	
		for(i=1;i<=m;i++)
			if(v[i]==0)
				if((vd[dau[i]] + vd[cuoi[i]])!=2)
				{
					v[i]=1;
					vd[dau[i]]=1;
					vd[cuoi[i]]=1;						
					break;
				}
		k++;
		
	}
	if(k == n-1) incay();
}

int main()
{
	nhap();
	khoidau();
	caybt();	
	getch();
}

