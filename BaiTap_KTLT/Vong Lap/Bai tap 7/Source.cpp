#include <stdio.h>
#include <conio.h>
#include <math.h>

/*
a = 25
b = 15

a = 25- 15 = 10
b = 15

a = 10
b = 15 - 10 = 5

a = 10 - 5 = 5
b = 5


*/
void main()
{
	int a,b;
	printf("Nhap a,b:\n");
	scanf_s("%d%d",&a,&b);

	a = abs(a);
	b = abs(b);
	  while( a != b)
	  {
		  if(a > b)
			  a = a - b;
		  else
			  b = b - a;
	  }

	  printf("UCLN la %d",a);
	  _getch();
}