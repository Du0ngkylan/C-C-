#include <stdio.h>
#include <conio.h>
void Thap(int n,char A,char B,char C)
{
   if(n==0)
      return;
   int i;
   Thap(n-1,A,C,B); 
   printf(" Chuyen tu %c sang %c\n",A,C);
   Thap(n-1,B,A,C);

}
main()
{
   int n;
   do
   {
      printf("\n Nhap vao so dia : ");   
      scanf("%d",&n);
   }
   while(n<1);
   Thap(n,'A','B','C');
   getch();
}

