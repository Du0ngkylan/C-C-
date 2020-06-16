//liet ke cac hoan vi cua n phan tu
#include"stdio.h"
#include"conio.h"
void in(int *a,int n)
{
     int i;
     for(i=1;i<=n;i++)
                     printf("%d\t",a[i]);
     printf("\n");
}
void Try(int i,int *a,int *b,int n)
{
     int j;
     
     for(j=1;j<=n;j++)
     {
          if(b[j]==0)
          {
              b[j]=1;
              a[i]=j;
              if(i==n)
                      in(a,n);
              else
                  Try(i+1,a,b,n);
              b[j]=0;
          }
     }
}

void khoitao(int *a,int n)
{
     int i;
     for(i=1; i<=n;i++)
             a[i]=0;
}


int main()
{
    int n;
    printf("nhap n=");                      
	scanf("%d",&n);
    int a[n],b[n];
    khoitao(b,n);
    Try(1,a,b,n);
    getch();
    return 0;
}
