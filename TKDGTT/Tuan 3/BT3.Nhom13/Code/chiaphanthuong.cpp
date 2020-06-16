#include<stdio.h>
#include<conio.h>
void nhap(int *m,int *n)
{
     printf("nhap so phan thuong = \t");
     scanf("%d",m);
     printf("nhap so hoc sinh = \t");
     scanf("%d",n);
}
/*
  Name: 
  Copyright: 
  Author: 
  Date: 08/03/12 08:10
  Description: 
*/
int chia(int m,int n)
{
    if(m == 0) return 1;
    if( n==0) return 0;
    if( m < n) return chia(m,m);
    else   return chia(m-n,n) + chia(m,n-1);
    
    
}
void xuat(int m,int n)
{
     printf("%d phan thuong chia cho %d hoc sinh co %d cach chia",m,n,chia(m,n));
}
int main()
{ 
     int n,m;
     nhap(&m,&n);
     xuat(m,n);
     getch();
     return 0;
     
}     
