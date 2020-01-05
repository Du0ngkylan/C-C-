#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int n, *x,*a,*b,*c;
// mang x: gia tri cua x[i] la vi tri cot cua quan hau tai hang i
int count;
void Init()
{
     printf("\n Nhap kich thuoc ban co n = ");scanf("%d",&n);
     x=(int*)calloc(n,sizeof(int));
     a=(int*)calloc(n,sizeof(int));
     b=(int*)calloc(n*2-1,sizeof(int));
     c=(int*)calloc((n-1)*2+1,sizeof(int));
     for(int i=0;i<n;i++)
             *(a+i)=1;
     for(int j=0;j<n*2;j++)
             *(b+j)=1;
     for(int k=0;k<(n-1)*2+1;k++)
             *(c+k)=1;
}

void PrintResult()
{
     for(int i=0;i<n-1;i++)
             printf(" %d ->  ",*(x+i)+1);
     printf(" %d\n",*(x+n-1)+1);
     count++;
}

void Try(int i)
{
     for(int j=0;j<n;j++ )
     if( *(a+j)==1&&*(b+i+j)==1&&*(c+i-j+n)==1)
     {
         *(x+i)=j;
         if(i==n-1)
         PrintResult();
     else
     {
         *(a+j)=0;
         *(b+i+j)=0;
         *(c+i-j+n)=0;
         Try(i+1);
         *(a+j)=1;
         *(b+i+j)=1;
         *(c+i-j+n)=1;
         }
     }
}
int main()
{
     count=0;
     Init();
     printf ("\n Cac phuong an co the la : \n");
     printf ("\n---------------------------------------\n");
     Try(0);
      printf ("\n---------------------------------------\n");
     printf("\n So phuong an : %d ( vi tinh chat doi xung cua ban co )",count/2);
     getch();
}
