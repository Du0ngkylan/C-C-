#include <stdio.h>
#include <conio.h>

int TimMax (int a[], int n)
{
	if (n == 1)
		return a[0];
	
	int max2 = TimMax (a, n-1);

	if (a[n-1] > max2)
		return a[n-1];
	
	return max2;
}

int main()
{
	//Tim max trong mang a
	
	int a[] = {9, 8, 11, 8, 5, 7};
	int n = sizeof(a) / sizeof(a[0]);
	
	printf("Max = %d", TimMax(a, n));

	_getch();
	return 0;
}