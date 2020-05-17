#include <stdio.h>
#include <conio.h>

int S (int n)
{
	if (n <= 1)
		return 1;
	
	return S(n-1) + n;
}

int main()
{
	//S(n) = 1 + 2 + 3 + ... + n
	
	printf("%d", S(4));

	_getch();
	return 0;
}