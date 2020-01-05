#include <stdio.h>
#include <conio.h>
int TinhGiaiThua(int n);

void GiamA(int a)
{
	a+= 5;
}
void TangA(int a)
{
	GiamA(a);
	a++;
}



void main()
{
	int n = 5;
	TangA(n);
	//int giaithua = TinhGiaiThua(n);
	//printf("%d! = %d",n,giaithua);
	_getch();
}

int TinhGiaiThua(int n)
{
	int giaithua = 1;
	for(int i = 1; i <= n; i++)
	{
		giaithua = giaithua * i;
	}
	return giaithua;
}