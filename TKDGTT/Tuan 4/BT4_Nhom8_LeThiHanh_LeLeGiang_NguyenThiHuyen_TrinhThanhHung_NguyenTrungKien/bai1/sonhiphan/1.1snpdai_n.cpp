//liet ke day nhi phan do dai n ?
#include<stdio.h>
#include<conio.h>
#define max 100
void result(int b[max],int n)
{
    int i;
    printf("\n\n");
    for(i=1;i<=n;i++)
         printf("%3d",b[i]);    
}
void tim(int b[max],int i,int n)
{
     int j;
     for(j=0;j<=1;j++)
     {
         b[i]=j;
         if(i==n)
             result(b,n);
         else
             tim(b,i+1,n);          
     }     
}

int main()
{
    int n,b[max];
    printf("nhap n =   ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        b[i]=0;
    tim(b,1,n);
    getch();
    return 0;        
}
