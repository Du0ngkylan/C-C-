#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
	int n;
	do 
	{
	printf("Nhap n:\n");
	scanf_s("%d",&n);
	 if(n <= 0 || n >= 50)
		 printf("Nhap khong hop le. Nhap lai!\n");
	}while(n <= 0 || n >= 50);

	int tong = 0;
	for(int i = 2; i <= n; i++)
	{
		int x = i;
		bool check = true;
		if(x < 2)
		{
			check = false;
		}
		else if(x > 2)
		{
			if(x % 2 == 0)
				check = false;
			else 
			{
				for(int i = 3; i <= (int)sqrt((float)x); i+= 2)
				{
					if(x % i == 0)
					{
						check = false;
						break;
					}
				}
			}
		}
		if(check == true)
			tong += x;
	}
	printf("Tong cac so nguyen to tu <= %d la %d",n,tong);
	_getch();
}