#include<conio.h>
#include<stdio.h>
void he2(long n)
{
     if (n<0)
     {
          printf ("\n Error : Nhap lai so tu nhien > 0 ");
          return ;
     }
     if (n/2 > 0)
        he2(n/2);
     printf ("%d",n&1);    
}

main ()
{
     long n;
     printf ("\n Nhap so nguyen : ");  scanf ("%d",&n);
     printf ("\n So %d doi ra he nhi phan la : ",n);
     he2(n);
     getch();
}
