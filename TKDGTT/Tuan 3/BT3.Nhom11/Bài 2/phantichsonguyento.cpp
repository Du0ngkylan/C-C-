/*
BAI 2
phan tich so nguyen thanh tich cac so nguyen to
*/
#include <stdio.h>
#include <conio.h>

int nguyento(int n)
{
   int i;
     if(n==1)
             return 0;
     else
     {
         i=2;
         while(n%i!=0)
                      i++;
         if(n/i!=1)
                    printf("%d.",i);
         else       printf("%d",i);
         nguyento(n/i);
     }
}
int main()
{
    int n, i=2;
    do
    {
    printf("Nhap n:");
    scanf("%d",&n);
    }
    while(n<=2);
    printf("so vua nhap duoc phan tich thanh\n");
    printf("%d=",n);
    nguyento(n);
    getch();
} 
