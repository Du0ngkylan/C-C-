//liet ke cac to hop k phan tu cua cac so tu 1 toi n
#include"stdio.h"
#include"conio.h"
void in(int *a,int n)
{
     int i;
     printf("\n");
     for(i=1;i<=n;i++)
                      printf("%d\t",a[i]);
     printf("\n");
}
void Try(int i,int *a,int k,int n)
{
     int j;
     for(j=a[i-1]+1;j<=n-k+i;j++)
     {
           a[i]=j;
           if(i==k)             in(a,k);
           else Try(i+1,a,k,n);
     }
}
int main()
{
    int n,k;
    printf("nhap n=");      scanf("%d",&n);
    printf("nhap k=");      scanf("%d",&k);
    int a[n];
    a[0]=0;
    printf("Cac to hop %d phan tu cua %d phan tu:\n",k,n);
    Try(1,a,k,n);
    getch();
    return 0;
}
