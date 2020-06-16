// ma di tuan
#include<conio.h>
#include<stdio.h>
#include<math.h>
#define n 8
int h[n][n];
int a[n]={2,1,-1,-2,-2,-1,1,2};
int b[n]={1,2,2,1,-1,-2,-2,-1};

void khoi_tao()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			h[i][j]=0;
		}
	}
}

void in_matran()
{
	for(int i=1;i<= n;i++)
	{
		for(int j =1;j<= n;j++)
		{
			printf("%5d",h[i][j]);
		}
		printf("\n");
	}
}

void ngua_tuan(int i,int x,int y)//buoc thu i,toa do x, toa do y
{
	int u,v;
	for(int k=0;k<n;k++)
	{
		u = x+a[k];
		v = y+b[k];
		if(1<=u && u<=n && 1<=v && v<=n && h[u][v]==0)
		{
			h[u][v]=i;
			if(i==n*n)
			{
				in_matran();
			}
			else
			{
				ngua_tuan(i+1,u,v);
				h[u][v]=0;
			}
		}
	}
}

int main()
{
	khoi_tao();
	h[1][1]=1;
	ngua_tuan(2,1,1);
	getch();
	return 0;
}
