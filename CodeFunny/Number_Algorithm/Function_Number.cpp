#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include"Function_Number.h"


int checkSoNguyenTo(int n){
	if (n<2) return 0;
	else {
		for (int i = 2; i <= sqrt(n); i++)
		if (n%i == 0)
			return 0;
		return 1;
	}
}

int checkSoChinhPhuong(int n){
	if (sqrt((float)n) == (int)sqrt((float)n))
		return 1;
	return 0;
}

int checkSoHoanThien(int n){
	long S;
	int i = 1;
	S = 0;
	while (i < n)
	{
		if (n % i == 0)
		{
			S = S + i;
		}
		i++;
	}
	if (S == n)
		return 1;
	return 0;
}

void MaxSoNguyen(int n){
	int max = 0;
	if (n == 0)
		max = 0;

	do
	{
		int i = n % 10;
		if (i > max)
		{
			max = i;
		}
	} while (n /= 10);

	printf("\nChu so lon nhat la %d", max);
}

void MinSoNguyen(int n){
	int min;
	min = n % 10;  // khởi tạo min
	if (n == 0)
		min = 0;
	do
	{
		int i = n % 10;
		if (i < min)
		{
			min = i;
		}
	} while (n /= 10);

	printf("\nChu so nho nhat la %d", min);
}

