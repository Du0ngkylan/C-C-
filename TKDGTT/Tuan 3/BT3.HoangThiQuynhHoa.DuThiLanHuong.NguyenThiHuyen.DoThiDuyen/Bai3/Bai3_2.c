//thuat giai chi de tri de tim max,min cua day so
#include"stdio.h"
#include"conio.h"
int Max(int *a,int l,int r)
{
    int m,max1,max2;
    if(r-l<=1)
        return (a[l]>a[r])? a[l]:a[r];
    else
    {
        m=(l+r)/2;
        max1=Max(a,l,m);
        max2=Max(a,m+1,r);
        return max1>max2? max1:max2;
    }
}
int Min(int *a,int l,int r)
{
    int m,min1,min2;
    if(r-l<=1)
              return (a[l]<a[r])? a[l]:a[r];
    else
    {
        m=(l+r)/2;
        min1=Min(a,l,m);
        min2=Min(a,m+1,r);
        return min1<min2? min1:min2;
    }
}
void nhap(int *a,int n)
{
     int i;
     for(i=0;i<n;i++)
     {
                     printf("a[%d]=",i);    scanf("%d",&a[i]);
     }
}
int main()
{
    int a[30],n;
    do
    {
        printf("nhap so phan tu cua mang n=");
        scanf("%d",&n);
    }while(n<=0);
    nhap(a,n);
    printf("gia tri lon nhat trong mang la:%d\n",Max(a,0,n-1));
    printf("Gia tri nho nhat trong mang la:%d",Min(a,0,n-1));
    getch();
    return 0;
}
