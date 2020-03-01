#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
int Max(int *a,int left,int right)
{
    int mid,max1,max2;
    if(right==left)
        return (a[left]>a[right])? a[left]:a[right];
    else
    {
        midle=(left+right)/2;
        max1=Max(a,left,mid);
        max2=Max(a,mid+1,r);
        return max1>max2? max1:max2;
    }
}
int Min(int *a,int left,int right)
{
    int mid,min1,min2;
    if(left==right)
              return (a[left]<a[right])? a[left]:a[right];
    else
    {
        mid=(left+right)/2;
        min1=Min(a,left,mid);
        min2=Min(a,mid+1,right);
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
    int a[100],n;
    do
    {
        printf("nhap n=");
        scanf("%d",&n);
    }while(n<=0);
    nhap(a,n);
    printf("gia tri lon nhat trong mang la:d\n",Max(a,0,n-1));
    printf("Gia tri nho nhat trong mang la:%d",Min(a,0,n-1));
    getch();
    return 0;
}
