//bai toan : ma di tuan 
#include<stdio.h>
#include<conio.h>
#define max 100

int a[8]= {1,1,-1,-1,-2,-2,2,2};
int b[8]= {2,-2,2,-2,1,-1,1,-1};
int count=0;

void inmatran(int h[][100], int n)
{
     printf("\n ma tran phuong an : \n\n\n");
     int i,j;
     for(i=1;i<=n;i++)
     {
         for(j=1;j<=n;j++)
         printf("%3d",h[i][j]);
         puts("");
     }
     printf("\n\n");
}

void inketqua(int h[][100], int n)
{    int k,i,j;
     for( k=1 ;k<= n*n ; k++)
         for(i=1;i<=n;i++)
              for(j=1;j<=n;j++)
                    if(h[i][j]==k)
                         printf("buoc %5d :<%d,%d>\n",k,i,j);
}

void Try(int i,int x,int y,int h[][100], int n)
{
        int u, v;
        for(int k=0;k<=7;k++)
        {
                 u=x+a[k];
                 v=y+b[k];
                if(1<=u&&u<=n&&1<=v&&v<=n&&h[u][v]==0)
                {
                                                      h[u][v]=i;
                                                      if(i<n*n)
                                                      {
                                                      Try(i+1,u,v,h,n);
                                                      h[u][v]=0;
                                                      }
                                                     else
			                                         {
                                                        count++;
                			                         	inmatran(h,n);
                			                         	printf("\n");
			                                            inketqua(h,n);
		                                              }
                }
                
        }
}

int main()
{
    int h[max][max],n;
    int x,y;
    printf("nhap cap cua ma tran vuong n = ");
    scanf("%d",&n);
    printf("nhap toa do xuat phat : \n x= ");
    scanf("%d",&x);
    printf(" y = ");
    scanf("%d",&y);
    h[x][y]=1;
    Try(2,x,y,h,n);
    if(count==0)
    printf("khong ton tai phuong an ");
    getch();
    return 0;
    
}
