#include <stdio.h>
#include <conio.h>
//===============================
void ThapHN(int n,char A,char B,char C)
{
   if(n==0)
      return;
   ThapHN(n-1,A,C,B); 
   printf(" Chuyen tu %c sang %c\n",A,C);
   ThapHN(n-1,B,A,C);
}
//===============================
main()
{
   int n,m;
   do
   {
      printf("\n Nhap vao so dia : ");      scanf("%d",&n);
   }while(n<1);
   printf("\n------------------------\n\n");
   ThapHN(n,'A','B','C');
   getch();
}

