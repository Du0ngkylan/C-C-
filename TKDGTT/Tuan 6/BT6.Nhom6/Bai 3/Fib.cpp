#include <stdio.h>
#include <conio.h>

int main()
{
   int n, F[100];
   //Khoi tao 2 gia tri ban dau la F[1] = 1 va F[2] = 1
   F[1] = 1;
   F[2] = 1;
   for (int i = 3; i <= 50; i++)
      F[i] = F[i - 1] + F[i - 2];//F[i] duoc xay dung tu cac sub-solution la F[i - 1] va F[i - 2]
   scanf("%d", &n);
   printf("%d", F[n]); //Cuoi cung chi can xuat so thu F[n] la xong :D
   getch();
   return 0;
}

