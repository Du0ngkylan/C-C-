//thuat giai de quy cua bai toan phan tich 1 so thanh tich cua cac thua so nguyen to
#include"stdio.h"
#include"conio.h"
int phantich(int n)
{
     int d;
     if(n==1)
             return 0;
     else
     {
         d=2;
         while(n%d!=0)
                      d++;
         if(n/d!=1)
                    printf("%d.",d);
         else       printf("%d",d);
         phantich(n/d);
     }
}
int main()
{
    int n;
    do{
          printf("nhap n=");
          scanf("%d",&n);
    }
    while(n<=1);
    printf("%d=",n);
    phantich(n);
    getch();
    return 0;
}
