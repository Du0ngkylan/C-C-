#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctime>
int *a,n,x;
void input()
{
     int i;
     srand(time(NULL));
     printf("\n Nhap vao so phan tu cua day:");
     scanf("%d",&n);
     a=(int*)calloc(n,sizeof(int));
     printf("\n Day ban dau:\n");
     for(i=0;i<n;i++)
     {
                     a[i]=rand()%100;
                     printf("%d ",a[i]);
     }
     printf("\n Nhap vao phan tu can tim x=");
     scanf("%d",&x);
}
void QuickSort(int *a,int l,int r)
{
     int i,j,t,z;
     if(l>=r);
     else
     {
         t=a[(l+r)/2];
         i=l;
         j=r;
         do
         {
             while(a[i]<t) i++;
             while(a[j]>t) j--;
             if(i<=j)
             {
                     z=a[i];
                     a[i]=a[j];
                     a[j]=z;
                     i++;
                     j--;
             }
         }while(i<j);
         QuickSort(a,l,j);
         QuickSort(a,i,r);
     }
}                     
int BinarySearch(int *a,int n, int x)
{
    int left=0, right = n-1;
    int middle;
    do
    {
        middle=(left+right)/2;
        if(x==a[middle]) break;
        else
            if(x<a[middle]) right=middle-1;
            else left=middle+1;
    }
    while(left<=right);
    if(left<=right) return middle;
    else return -1; // khong tim thay
}
int main()
{
    int i;
    input();
    QuickSort(a,0,n-1);
    printf("\n Day sau khi duoc sap xep bang thuat toan Quicksort:\n");
    for(i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n Tim kiem nhi phan tren day da sap xep:");
    if(BinarySearch(a,n,x)==-1) printf("\n Khong co x trong day a");
    else printf("\n co x trong day\n");
    getch();
}
