#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int  n,*x,*a,*b,*c;
int count;
void khoitao()
{
     printf("nhap n= "); scanf("%d",&n);
     x= (int *)calloc(n,sizeof(int));
     a=(int *)calloc(n,sizeof(int));
     b=(int*)calloc(n*2-1,sizeof(int));
     c=(int*)calloc((n-1)*2+1,sizeof(int));
     for(int i=0;i<n;i++)
             *(a+i)=1;
     for(int j=0;j<n*2;j++)
             *(b+j)=1;
     for(int k=0;k<(n-1)*2+1;k++)
             *(c+k)=1;
     
 }
 void in()
 {
      for(int i=0;i<n-1;i++)
      printf("%d",*(x+i)+1);
      printf("%d\n",*(x+n-1)+1);
      count++;
  }
void thu(int i)
 {
      for(int j=0;j<n;j++)
      if(*(a+j)==1&&*(b+i+j)==1&&*(c+i-j+n)==1)
      {
      *(x+i)=j;
      if(i==n-1)
      in();
      else
      {
          *(a+j)=0;
          *(b+i+j)=0;
          *(c+i-j+n)=0;
          thu(i+1);
          *(a+j)=1;
          *(b+i+j)=1;
          *(c+i-j+n)=1;
      }
                                                                                    
      }
  }
int main()
  {
          count=0;
       khoitao();
       thu(0);
       printf("so phuong an %d",count/2);
       getch();
       exit(0);
   }

