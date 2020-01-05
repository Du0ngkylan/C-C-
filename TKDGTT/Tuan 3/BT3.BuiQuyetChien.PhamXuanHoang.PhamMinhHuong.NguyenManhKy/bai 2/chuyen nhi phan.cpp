//Nhap vao mot so phan thap phan, chuyen thanh so nhi phan
#include <stdio.h>
#include <conio.h>
 
main()
{
    int n,dem,i;
   int  thuong;
    int MangSoDu[100];
 
   printf("nNhap vao so can chuyen:");
   scanf("%d", &n);
 
   dem=0;
   do
   {
       thuong = n / 2;
      MangSoDu[dem] = n %2;
      n=thuong;
      dem++;
   } while(thuong!=0);
   printf("nSo nhi phan tim duoc la: ");
   for(i = dem -1; i>= 0; i--)
   {
       printf("%d", MangSoDu[i]);
   }
   getch(); 
}  
