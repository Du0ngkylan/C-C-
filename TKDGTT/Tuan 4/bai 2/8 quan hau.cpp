#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int khoitao(int *a,int n) 
{
    for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                    *(a+i*n+j)=0;
}
void in(int *a,int n)
{
    for(int i=1;i<=n;i++)
    {
            for(int j=1;j<=n;j++)
                    printf("%3d",*(a+i*n+j));
            printf("\n");
    }
    
}
int CheckRow(int *a,int i,int n)
{
    int d=0;
    for(int j= 1;j<=n;j++)
            if(*(a+i*n+j)!=0)
                             d++;
    if(d==0) return 1;
    else return 0;
}
int CheckColunm(int *a,int j,int n)
{
    int d=0;
    for(int i= 1;i<=n;i++)
            if(*(a+i*n+j)!=0)
                             d++;
    if(d==0) return 1;
    else return 0;
}
int CheckCheoChinh(int *a,int i,int j,int n)
{
    int d=0;
    int t=i;
    int k=j;
    while(t>=1 && k>=1)
    {
               if(*(a+t*n+k)!=0)
                                d++;
               t--;
               k--;
    }
    while(i<=n && j<=n)
    {
               if(*(a+i*n+j)!=0)
                                d++;
               i++;
               j++;
    }
    if(d==0) return 1;
    else return 0;
}
int CheckCheoPhu(int *a,int i,int j,int n)
{
    int d=0;
    int t=i;
    int k=j;
    while(t<=n && k>=1)
    {
               if(*(a+t*n+k)!=0)
                                d++;
               t++;
               k--;
    }
    while(i>=1 && j<=n)
    {
               if(*(a+i*n+j)!=0)
                                d++;
               i--;
               j++;
    }
    if(d==0) return 1;
    else return 0;    
    
}
int Try(int *a,int i,int n)
{
    for(int h=1;h<=n;h++)
            for(int g=1;g<=n;g++)
            {
                    if(*(a+h*n+g)==0 && CheckRow(a,h,n)==1 && CheckColunm(a,g,n)==1 && CheckCheoChinh(a,h,g,n)==1 && CheckCheoPhu(a,h,g,n)==1)
                    {
                                        *(a+h*n+g)=1;
                                        if(i==n)
                                        {
                                                 printf("\n");
                                                in(a,n);
                                                break;
                                        }
                                        else
                                            Try(a,i+1,n);
                                        *(a+h*n+g)= 0 ;
                    }
            }
}
int main()
{
    int *a,n,check = 0;
    printf("\nNHap n = ");
    scanf("%d",&n);
    a = (int*)calloc(n*n,sizeof(int));
    khoitao(a,n);
    Try(a,1,n);
    getch();
    return 0;
}
