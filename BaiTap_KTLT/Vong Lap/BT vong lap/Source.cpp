#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
	// Bài 1: Kiểm tra 1 số có phải số đối xứng ko?
	int n;
	printf("Nhap n:\n");
	scanf_s("%d",&n);
	int temp = n;
	int sodaonguoc = 0;
	   while(temp != 0)
	   {
		   sodaonguoc = (sodaonguoc * 10) + (temp % 10);
		   temp /= 10;
	   }
	   if(n == sodaonguoc)
	    printf("%d la so doi xung",n);
	   else 
		   printf("%d khong phai so doi xung",n);

	   /*
	     temp = 12345
		 sodaonguoc = 0
		 sodaonguoc = 0 * 10 + 5 = sodaonguoc = 5
		 temp = 12345 / 10 = 1234
		 sodaonguoc = 5 * 10 + 4 = 54
		 temp = 1234 / 10 =123
		 sodaonguoc = 54 * 10 + 3 = 543
		 temp = 123 / 10 = 12
		 sodaonguoc = 543 * 10 + 2 = 5432
		 temp = 12 / 10 = 1

		 sodaonguoc = 5432 * 10 + 1 = 54321
		 temp = 1 / 10 = 0
	   */

	   /* Bài 2: Kiểm tra số chính phương */
	   int canbac2 = sqrt((float)n);
	   if(canbac2 * canbac2 == n) 
		   printf("\n%d la so chinh phuong",n);
	   else 
		   printf("\n%d khong phai so chinh phuong",n);

	   /* Bài 3: Kiểm tra số nguyên tố */
	   bool checkNT = true; 
	   if(n < 2)
		   checkNT = false;
	   else if(n > 2)
	   {
		   if(n % 2 == 0)
			   checkNT = false;
		   else 
		   {
			   for(int i = 3; i <= (int)sqrt((float)n); i += 2)
			   {
				   if(n % i == 0)
				   {
					   checkNT = false;
					   break;
				   }
			   }
		   }
	   }
	   if(checkNT == true)
		   printf("\n%d la so nguyen to",n);
	   else 
		   printf("\n%d khong phai so nguyen to",n);

	   /* Tim chữ số max*/
	   int chusomax  = n % 10;
	   temp = n;
	   while(temp != 0)
	   {
		   int chuso = temp % 10;
		   if(chuso > chusomax)
			   chusomax = chuso;
		   temp /= 10;
	   }
	   printf("\nChu so lon nhat la %d",chusomax);
	   _getch();
}