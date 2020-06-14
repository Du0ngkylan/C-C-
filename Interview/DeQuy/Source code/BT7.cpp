#include <stdio.h>
#include <conio.h>

int ToanChuSoLe (int N)
{
	if (N < 10)
		return (N % 2 == 1);
	
	int HangDonVi = N % 10;
	return (HangDonVi % 2 == 1) && ToanChuSoLe(N/10);
}

int main()
{
	//Kiem tra N co toan chu so le hay khong
	
	int N = 1297;
	
	if (ToanChuSoLe(N))
		printf("%d co toan chu so le", N);
	else
		printf("%d KHONG co toan chu so le", N);
	
	_getch();
	return 0;
}