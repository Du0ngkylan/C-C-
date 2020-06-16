#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int min(int x,int y)
{
	if(x > y)
	 return y; 
	else return x;
}
int max(int x,int y)
{
	if(x > y) return x; 
	else return y;
}
int *MinMax(int a[],int L,int R)
{
	int min1,min2,max1,max2;
	int *p,*p1,*p2;
	p=(int*)malloc(10*sizeof(int));
	p1=(int*)malloc(10*sizeof(int));
	p2=(int*)malloc(2*sizeof(int));
          if (R-L<=1){ 
		*(p+1)=min(a[L],a[R]);
		*(p+2)=max(a[L],a[R]);
             return p;
          } 
          else {
				
            p1 = MinMax(a,L,(L+R)/2);
             p2 = MinMax(a,(L+R)/2+1,R);
             min1= *(p1+1);
             max1= *(p1+2);
             min2= *(p2+1);
             max2= *(p2+2);
             *(p+1)=min(min1,min2);
			*(p+2)=max(max1,max2);
             return p;
          }
}
int main()
{
	int a[100],n,i,*d;
	d=(int *)malloc(10*sizeof(int));
	printf("\nNhap n =");scanf("%d",&n);
	printf("\nNhap cac phan tu cua mang ");
	for(i=0;i<n;i++)
	{printf("\na[%d]=",i);
	scanf("%d",&a[i]);}
	d=MinMax(a,0,n-1);
	printf("\nMin cua mang la = %d",*(d+1));
	printf("\nMax cua mang la = %d",*(d+2));
	getch();
	return 0;
	
}
