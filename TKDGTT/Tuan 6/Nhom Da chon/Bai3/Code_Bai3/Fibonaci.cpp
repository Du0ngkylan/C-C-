#include<stdio.h>
#include<conio.h>
//=================================
int main()
{
   int n, F[100];
   printf ("\n Nhap gia tri n : ");
   scanf("%d", &n);
   F[1] = 1; // Khoi tao 2 gia tri ban dau la F[1] = 1 va F[2] = 1
   F[2] = 1;
   for (int i = 3; i <= 50; i++) 
      F[i] = F[i - 1] + F[i - 2]; //F[i] duoc xay dung tu cac sub-solution la F[i - 1] va F[i - 2]
   printf("\n F(%d) = %d ",n, F[n]); //Cuoi cung chi can xuat so thu F[n] la xong :D
   getch();
}
