/*
viet thuat giai chia de tri de tim kiem phan tu tren mang duoc sap
*/
#include"stdio.h"
#include"conio.h"
int kiemtra(int *a,int n)
{
    int i;
    for(i=0;i<n-1;i++)
        if(a[i]>a[i+1])
             return 0;
    return 1;
}
void nhap(int *a,int n)
{
     int i;
     for(i=0;i<n;i++)
     {
                     printf("a[%d]=",i);
                     scanf("%d",&a[i]);
     }
}
int BinarySearch(int *a,int x,int l,int r)
{
    int m,i;
    if(l==r)
    {            
            if(a[l]==x)     return l;
            else            return -1;   
    }
    else
    {
        m=(l+r)/2;
        if(x==a[m])         return m;
        else
        {
            if(x<a[m]) 
                            return BinarySearch(a,x,l,m);
            else            return BinarySearch(a,x,m+1,r);
        }
    }
}

int main()
{
    int n,a[20],x;
    printf("nhap so phan tu cua mang n=");
    scanf("%d",&n);
    printf("nhap cac phan tu cua mang:\n");
    nhap(a,n); 
    
    if(kiemtra(a,n)==0)
    {
                       printf("day nhap vao phai theo thu tu tang dan!");   getch();
                       return 0;
    }
    printf("nhap phan tu can tim x=");
    scanf("%d",&x);
    int k=BinarySearch(a,x,0,n-1);
    if(k==-1)
                                   printf("khong co %d trong day");
    else                          
    {
          printf("vi tri cua %d trong day la %d",x,k);
    }

    getch();
    return 0;
}
