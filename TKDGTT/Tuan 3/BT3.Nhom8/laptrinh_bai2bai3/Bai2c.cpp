#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int Fib(int n)
{
	int d;
    if (n==1||n==2)
        d = 1;
    else
        d = Fib(n-1)+Fib(n-2);
    return d;
}
int main()
{
	int n,d;
	printf("\nNhap n= ");scanf("%d",&n);
	d= Fib(n);
	printf("\nKet qua la = %d",d);
	getch();
	return 0;
}
