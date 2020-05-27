#include <stdio.h>
#include <conio.h>

float T (int n)
{
	if (n <= 1)
		return 0.5;
	
	return T(n-1) + (float)n/(n+1);
}

int main()
{
	//T(n) = 1/2 + 2/3 + ... + n/(n+1)
	
	printf("%f", T(3));

	_getch();
	return 0;
}