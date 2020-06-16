/*
bai 2_1:lap trinh cho thuat giai  de quy cho bai toan: in bieu dien nhi phan cua 1 so nguyen
*/
#include"stdio.h"
#include"conio.h"
void Int2Bin(int n)
{
     if(n>0)
     {
            Int2Bin(n/2);
            printf("%d",n%2);
     }
}
int main()
{
    int n;
    do
    {
       printf("nhap n=");
       scanf("%d",&n);
    }
    while(n<=0);
    printf("Bieu dien nhi phan cua %d la:",n);
    Int2Bin(n);
    getch();
}
