#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
    
    int b,c,d,mang[100],tong;
    int dem=0;
    int a[4]={50000,20000,10000,1000};
     printf("\nnhap vao so tien can doi:");
    scanf("%d",&b);
    for(int i=0;i<=50000;i++)
    {
            for(int j=0;j<=20000;j++)
            {
                    for(int k=0;k<=10000;k++)
                    {
                            for(int h=0;h<=1000;h++)
                            if(i*50000+j*20000+k*10000+h*1000==b)
                            {
                                                                 c=i+j+k+h;
                                                                  printf("%d\n",c);    
                                                                                  }
                                                                 }
                                                           
                            } 
                           
    }
    
    getch();
    }
