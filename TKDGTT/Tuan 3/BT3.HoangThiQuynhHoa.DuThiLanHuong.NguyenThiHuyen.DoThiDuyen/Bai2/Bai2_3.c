//bai 2_3: viet thuat giai de quy tim so fibonaci thu n
#include"stdio.h"
#include"conio.h"
int Fib(int n)
{
    if(n==1||n==2)
                  return 1;
    else
    {
        return Fib(n-1)+Fib(n-2);
    }
}
int main()
{
    int n;
    do
    {
          printf("nhap n=");
          scanf("%d",&n);
    }while(n<=0);
    printf("so Fibonaci thu %d la:%d",n,Fib(n));
    getch();
    return 0;
}
