#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>

void main()
{
	// Bài 1
	//char kytu;
	//do 
	//{
	//	system("cls");       // cls viết tắt là clear screen
	//	printf("Nhap vao 1 ky tu bat ky:\n");
	//	kytu = _getch();
	//	if(kytu >= 'a' && kytu <= 'z')
	//	{
	//		printf("%c %c",kytu, kytu - 32);
	//	}
	//	else if(kytu >= 'A' && kytu <= 'Z')
	//	{
	//		printf("%c %c",kytu, kytu + 32);
	//	}
	//	else if(kytu >= '0' && kytu <= '9')
	//	{
	//		printf("%c",kytu);
	//	}
	//	else if(kytu >= 0 && kytu <= 31)
	//	{
	//		exit(0);
	//	}
	//	_getch();
	//}while(true);
	// Bài 2
 /*int n;
 float x, tong = 0, tong2 = 0;
 printf("nhap x va n : ");
 scanf_s("%f%d",&x,&n);
 for(int i = 0; i < n;i++)
 {
  tong  = sqrt(x + tong);
 }
 for(int i = 0; i <= n;i++)
 {
	 tong2 = tong2 + (pow(x, i) / (i + 1));
 }
 printf("ket qua la %f\n%f ",tong,tong2);*/
	// Bài 3
	/*int n;
	printf("Nhap n:\n");
	scanf_s("%d",&n);
	int temp = n;
	while(temp != 0)
	{
		int chuso = temp % 10;
		bool check = true;
		if(chuso < 2)
			check = false;
		else if(chuso > 2)
		{
			if(chuso % 2 == 0)
				check = false;
			else 
			{
				for(int i = 3; i <= (int)sqrt((float)chuso); i += 2)
				{
					if(chuso % i == 0)
					{
						check = false;
						break;
					}
				}
			}
		}
		if(check == true)
			printf("%d ",chuso);
		temp = temp / 10;
	}*/
	/* Bài 5  */
	/*for (int i = 100; i < 1000; i++)
	{
		int temp = i;
		int tongchuso = 0, tichchuso = 1;
           while(temp != 0)
             {
                 int chuso = temp % 10; 
                 tongchuso += chuso;
                 tichchuso *= chuso;
                 temp /= 10;
             }
		if (tichchuso == tongchuso)
		{
			printf("%d ",i);
		}
	}*/
	/* Bài 6: Vẽ HCN */
	/*int CD, CR;
	do 
	{
		printf("Nhap chieu dai, chieu rong:\n");
		scanf_s("%d%d",&CD,&CR);
		if(CD < 0 || CR < 0)
			printf("Du lieu khong hop le. Nhap lai!\n");
	}while(CD < 0 || CR < 0);
	for(int i = 0; i < CR; i++)
	{
		for(int j = 0; j < CD; j++)
		{
			printf("*");
		}
		printf("\n");
	}*/
   // Bài 7. Vẽ hình vuông
   /* int canh;
	do 
	{
		printf("Nhap canh:\n");
		scanf_s("%d",&canh);
		if(canh < 0)
			printf("Du lieu khong hop le. Nhap lai!\n");
	}while(canh < 0);
	for(int i = 0; i < canh; i++)
	{
		for(int j = 0; j < canh; j++)
		{
			printf("* ");
		}
		printf("\n");
	}*/
    // Bài 9: Vẽ tam giác cân
     int h;
	 do 
	 {
		 printf("Nhap chieu cao tam giac can:\n");
		 scanf_s("%d",&h);
		 if(h < 0)
			 printf("Chieu cao khong hop le. Nhap lai!\n");
	 }while(h < 0);

	/* for(int i = 0; i < h - 1; i++)
	 {
		 for(int j = 0; j < h * 2; j++)
		 {
			 if(j == h - i || j == h + i)
				 printf("*");
			 else 
				 printf(" ");
		 }
		 printf("\n");
	 }
	 printf(" ");
	 for(int i = 0; i < h * 2 - 1; i++)
	 {
		 printf("*");
	 }*/

	  for(int i = 0; i < h / 2; i++)
	 {
		 for(int j = 0; j < h * 2; j++)
		 {
			 if(j == h - i || j == h + i)
				 printf("*");
			 else 
				 printf(" ");
		 }
		 printf("\n");
	 }
	   for(int i = h / 2 - 2; i >= 0; i--)
	 {
		 for(int j = 0; j < h * 2; j++)
		 {
			 if(j == h - i || j == h + i)
				 printf("*");
			 else 
				 printf(" ");
		 }
		 printf("\n");
	 }
	_getch();
}