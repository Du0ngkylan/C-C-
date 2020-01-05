#include<stdio.h>
#include<conio.h>
int GT(int n)
{
    if(n==0)
        return 1;
    else 
        return n*GT(n-1);
}
int main()
{
    int n;
    printf("Nhap n: "); scanf("%d",&n);
    printf("\n%d! = %d",n,GT(n));
    getch();
}
