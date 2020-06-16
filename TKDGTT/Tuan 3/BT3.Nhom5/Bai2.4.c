// Bai toan thap Ha Noi de quy
#include<stdio.h>
#include<conio.h>
int d=1;
void Chuyen_Dia(int n, int c1, int c2,int c3)
{
 if(n==1) printf("\n\t%d ->%d",c1,c2);
 else
    {
        d=d+2;
     Chuyen_Dia(n-1,c1,c3,c2);
     Chuyen_Dia(1,c1,c2,c3);
     Chuyen_Dia(n-1,c3,c2,c1);
      
    }
}

main()
  {
   int n,c1=1,c2=2,c3=3;
   printf("\nNhap so dia can chuyen: ");scanf("%d",&n);   
   Chuyen_Dia(n,c1,c2,c3);
   printf("\n\n ======= So buoc chuyen : %d",d);
   getch();
   return 0;
}
