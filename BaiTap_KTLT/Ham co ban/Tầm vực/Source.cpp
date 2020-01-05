#include <stdio.h>
#include <conio.h>
int b;     // Tầm vực của biến b là toàn cục

void Xuata()
{
	printf("%d",b);
}

void main()
{
	int a = 1;   // Biến a ở tầm vực là cục bộ
	
	_getch();
}