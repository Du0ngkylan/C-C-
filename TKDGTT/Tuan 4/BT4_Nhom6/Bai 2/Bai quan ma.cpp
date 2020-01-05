#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
//===================================
int p[8] = {-2,-2,-1,-1,1,1,2,2};
int q[8] = {-1,1,-2,2,-2,2,-1,1};
int d=0,x,y,n,a[50][50];
//===================================
void inkq()
{
     printf ( "\n Cach di thu %d \n\n" , ++d );
     for (int i=0;i<n;i++)
     {
         for (int j=0;j<n;j++)
         printf("%3d",a[i][j]);
         printf ("\n");
     }
     getch();
}
//===================================
void tim(int x, int y, int k)
{
     if (k>n*n) inkq();
     else
     for (int i=0;i<8;i++)
     {
          int x1=x+p[i],y1=y+q[i];
          if (x1>=0 && x1<n && y1>=0 && y1<n)
          if (a[x1][y1]==0)
          {
             a[x1][y1]=k;
             tim(x1,y1,k+1);
             a[x1][y1]=0;
          }
     }
}
//===================================
int main()
{
    printf ("\n Nhap kich thuoc ban co : ") ;   scanf ("%d",&n);
    printf ("\n Nhap vi tri xuat phat x,y : ");  
           scanf ("%d",&x);
           scanf ("%d",&y);
    for (int i=0;i<n;i++)
    for (int j=0;j<n;j++)
    a[i][j]=0;
    a[x][y]=1;
    tim(x,y,2);
    if (d==0)
    printf ("\n Khong ton tai cach di thoa man");
    else
    printf ("\n Co tat ca &d cach di thoa man",d );
    getch();
    return 0;
}
