#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
int n;
int *x;
void nhap()
{
     printf("n=");
     scanf("%d",&n);
     x=(int*)calloc(n,sizeof(int));
     }
void in()
{
     for(int i=0;i<n;i++)
          printf("%d",*(x+i));
     printf("\n");
     }
void Try(int i)
{
     int j;
     for(j=0;j<=1;j++)
     {
                      *(x+i)=j;
                      if(i<n-1)
                            Try(i+1);
                      else
                            in();
                            }
}
int main()
{
     nhap();
     Try(0);
     getch();
}
