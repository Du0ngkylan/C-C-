#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#define max 8
void result(int p[max], int n)
{
     static int count=0;
     int i=1;
     printf("\nHoan vi thu %d:",++count);
     for(i=1;i<=n;i++)
          printf("%3d",p[i]);
}
void hoanvi(int i, int p[max], int b[max], int n)
{
     int j;
     for(j=1;j<=n;j++)
          if(b[j]==1)
          {
               p[i]=j;
               b[j]=0;
               if(i==n) result(p,n);
               else hoanvi(i+1,p,b,n);
               b[j]=1;
               }
}
int main()
{
    int p[max], b[max], n, i=1;
    printf("Nhap n:\n");
    scanf("%d", &n);
    for(i=1;i<=n;i++)
         b[i]=1;
    hoanvi(1,p,b,n);
    getch();
    return 0;
}
