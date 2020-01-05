#include <stdio.h>
#include <conio.h>

void NhiPhan(int n)
{
   if (n>=0)
   {
     if (n/2>0)
     NhiPhan(n/2);
     printf("%d",n%2);
   }
} 

main()
{
    int n;
    printf("Nhap n: "); scanf("%d",&n);
    printf("\nBieu dien nhi phan cua %d la: ",n);
    NhiPhan(n);
    getch();
}
    
