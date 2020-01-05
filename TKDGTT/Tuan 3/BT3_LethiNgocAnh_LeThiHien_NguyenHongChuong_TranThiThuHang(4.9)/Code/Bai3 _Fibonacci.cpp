#include <conio.h>
#include <stdio.h>
/*Ham tra ve so nguyen tinh gia tri Fibonacci thu n*/
int F(int n) 
{
   if(n==1 || n==2)
      return 1;
   else
      return F(n-1) + F(n-2);
}
/*Chuong trinh chinh*/
main()
{
   int n;
   printf ("\n Nhap vao gia tri cua n = ");
   scanf ("%d",&n);
   printf("\n -------------------------\n");
   printf ("\n Ket qua : F(%d) = %d " ,n,F(n));
   getch();
}
