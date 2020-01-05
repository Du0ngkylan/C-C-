#include <stdio.h>
#include <conio.h>

void HoanVi(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

void NhapSoNguyen(int& a)
{
	printf("Nhap so nguyen:\n");
	scanf_s("%d",&a);
}

void main()
{
	int x = 1, y = 2;
	HoanVi(x, y);
	printf("x = %d, y = %d",x,y);
	int n; 
	NhapSoNguyen(n);  // int& a = n;
	_getch();
}