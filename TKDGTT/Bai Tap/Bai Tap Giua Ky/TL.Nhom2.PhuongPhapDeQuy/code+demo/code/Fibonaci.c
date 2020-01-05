// Tim so Fibonacci thu n
#include <stdio.h>
#include <conio.h>

int Fibo (int n)
{
    if (n==0) return 0;
    if (n==1) return 1;
    return Fibo(n-1) + Fibo(n-2);
}

main()
{
    int n;
    printf(" Nhap n: "); scanf("%d",&n);
    printf("So Fibonacci thu %d la: %d",n,Fibo(n));
    getch();
    return 0;
}
    
