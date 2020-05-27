#include <stdio.h>
#include <conio.h>

int P (int x, int n)
{
	if (n <= 0)
		return 1;
	
	return P(x, n-1) * x;
}

int main()
{
	//P(x,n) = x^n = x mu~ n
	
	printf("%d", P(2, 3));

	_getch();
	return 0;
}