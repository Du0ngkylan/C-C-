#include <stdio.h>
#include <conio.h>
#include <math.h>

float R (int n)
{
	if (n == 1)
		return 1;
	
	return sqrt(n + R(n-1));
}

int main()
{
	//Tinh can(n + can(n-1 + can(n-2 + can (...+ 1))))
	
	int n = 4;
	
	printf("R(%d) = %f", n, R(n));

	_getch();
	return 0;
}