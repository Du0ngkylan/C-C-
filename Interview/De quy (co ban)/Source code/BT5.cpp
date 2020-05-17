#include <stdio.h>
#include <conio.h>

int ToanSoDuong (int a[], int n)
{
	if (n == 1)
		return (a[0] % 2 == 0);
	
	return ToanSoDuong(a,n-1) && (a[n-1] % 2 == 0);
}

int main()
{
	//ToanSoDuong(n) = mang a (tu a[0] ==> a[n-1]) co toan so duong
	
	int a[10] = {2, 1, -6, 2, 4};
	int n = sizeof(a) / sizeof(a[0]);
	
	int KetQua = ToanSoDuong(a,n);
	
	if (KetQua == 1)
		printf("Mang a co toan so duong");
	else
		printf("Mang a KHONG co toan so duong");
	
	_getch(); 
	return 0;
}