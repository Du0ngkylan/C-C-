#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
int  dx[]={2, 1, -1, -2, -2, -1, 1, 2};
int  dy[]={1, 2, 2, 1, -1, -2, -2, -1};
int n=8;
int h[8][8];
void khoitao(int h[8][8], int n, int x, int y)
{
	int i, j;
	for(i=0;i<n;i++)
	 for(j=0;j<n;j++) 
     h[i][j]=0;
	 h[x][y]=1;
}
void in(int h[8][8], int n)
{
	int i, j;
	for(i=0;i<n;i++)
	{
	 for(j=0;j<n;j++)
	   printf(" %3d,", h[i][j]);
	   printf("\n");
	}
	printf("\n--------------------------\n");
}

void Try(int i, int x, int y, int h[8][8])
{
     int j, u, v;
     for(j=0;j<8;j++)
     {
         u=x+dx[j];
         v=y+dy[j];
         if(h[u][v]==0 && 0<=u && u<n && 0<=v && v<n)
         {
         h[u][v]=i+1;
         if(i==n*n-1)
           {
        	in(h,n);
        	exit(0);
        	}
          else
        	Try(i+1,u,v,h);
          h[u][v]=0;
          in(h,n);
         }
     }
}
int main()
{
	int x,y;
	printf("Nhap vi tri ban dau: ");
	scanf("%d%d",&x, &y);
	khoitao(h,n, x,y);
	Try(1, x,y,h);
	getch();
	return 0;
}
