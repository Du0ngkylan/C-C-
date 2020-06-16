/*Ham tra ve so nguyen tinh gia tri Fibonacci thu n*/
#include <conio.h>
#include <stdio.h>
#include<stdlib.h>

int Fi(int n) 
{
   if(n==1 || n==2)
      return 1;
   else
      return Fi(n-1) + Fi(n-2);
}

main()
{
   int n;
   printf ("\n Nhap vao gia tri cua n = ");
   scanf ("%d",&n);
   printf ("\n Ket qua : F(%d) = %d " ,n,Fi(n));
   getch();
}
