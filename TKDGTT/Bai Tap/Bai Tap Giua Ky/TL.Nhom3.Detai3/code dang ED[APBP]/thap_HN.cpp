#include<stdio.h>
#include<conio.h>

void CHUYEN_THAP(int n, int c1, int c2,int c3)
{
     if(n==1)
              printf("\n\t%d -->%d",c1,c2);
     else
     {
              CHUYEN_THAP(n-1,c1,c3,c2);
              CHUYEN_THAP(1,c1,c2,c3);
              CHUYEN_THAP(n-1,c3,c2,c1);
     }
}

int main()
{
   int n,c1=1,c2=2,c3=3;
   printf("Nhap vao so dia can chuyen n = ");
   scanf("%d",&n);
   printf("Cac buoc chuyen la:");
   CHUYEN_THAP(n,c1,c2,c3);
   getch();
   return 0;
}
