#include <stdio.h>
#include <conio.h>
using namespace std;
void main()
{
	int a = 3, b = 2;
	int tich = 2, tich2 = 2;
	tich *= a + b;
	tich2 = tich2 * a + b;
	printf("tich = %d, tich2 = %d",tich, tich2);
	_getch();
}