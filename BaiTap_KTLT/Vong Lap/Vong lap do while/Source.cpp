#include <stdio.h>
#include <conio.h>


void main()
{
	int namsinh;
	do
	{
	printf("Nhap nam sinh:\n");
	scanf_s("%d",&namsinh);
	   if(namsinh < 0)
		   printf("Nam sinh ko hop le. Nhap lai!\n");
	}while(namsinh < 0);

	int tuoi = 2015 - namsinh;
	printf("\nTuoi cua ban la %d",tuoi);
	_getch();
}