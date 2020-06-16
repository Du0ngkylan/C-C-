#include<stdio.h>
#include<conio.h>

int n , m;
void Input()
{
   printf("Nhap vao so hoc sinh n: ");
   scanf("%d",&n);
   printf("Nhap vao so phan thuong m (m >= n):  "); 
   scanf("%d",&m); 
}

int chiaPhanThuong(int m,int n)
{
    if(m == 0) return 1;
    if( n==0) return 0;
    if( m < n) return chiaPhanThuong(m,m);
    else   return chiaPhanThuong(m-n,n) + chiaPhanThuong(m,n-1);
}

void OutPut(int k)
{
    printf("Chia %d phan thuong cho %d hoc sinh co %d cach.\n",m,n,k);     
}

int main()
{
    Input();
    int k = chiaPhanThuong(m,n);
    OutPut(k);
    getch();
}
