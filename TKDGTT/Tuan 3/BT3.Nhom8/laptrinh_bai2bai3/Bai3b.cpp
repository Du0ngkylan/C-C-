#include<stdio.h>
#include<conio.h>
int  BinarySearch(int a[],int x, int L,int R)
{
	int M;
    if (L==R) return (x==a[L] ? L : -1);
    else {
        M = (L+R)/2;
        if (x == a[M]) return (M);
		else
		{
            if (x<a[M]) BinarySearch(a,x,L,M);
            else BinarySearch(a,x,M+1,R); 
        }
    }
}
int main()
{
	int a[100],n,i,d,x;
	printf("\nNhap n =");scanf("%d",&n);
	printf("\nNhap phan tu can tim x =");scanf("%d",&x);
	printf("\nNhap cac phan tu cua mang ");
	for(i=1;i<=n;i++)
	{printf("\na[%d]=",i);
	scanf("%d",&a[i]);}
	d=BinarySearch(a,x,1,n);
	if(d== -1) printf("\nKhong tim thay");
	else printf("\nTim thay no o vi tri %d",d);
	getch();
	return 0;
	
}
