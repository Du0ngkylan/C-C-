#include <iostream>
#include <ctime>
using namespace std;

int Tong(int n)
{
	if(n == 0)
	{
		return 0;
	}
	else 
		return Tong(n - 1) + n;
}
int TinhGiaiThua(int n)
{
	if(n  == 1)
		return 1;
	else 
		return TinhGiaiThua(n - 1) * n;
}
int VT(int n)
{
   if(n == 0)
    return 2;
   return VT(n - 1) * 2;
}
int BinarySearch(int a[], int left, int right, int x)
{
	if(left > right)
		return -1;
	else 
	{
		int mid = a[(left + right) / 2];
		if(x > mid)
		{
			return BinarySearch(a, mid + 1, right, x);
		}
		else if(x < mid)
		{
			return BinarySearch(a, left, mid - 1, x);
		}
		else 
			return (left + right) / 2;
	}
}
void TaoNgauNhien(int* a, int n)
{
	srand(time(0));
	for(int i = 0; i < n; i++)
	{
		a[i] = rand()%1000;
	}
}
void XuatMang(int* a, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout<<a[i]<<"\t";
	}
}
int SoSanhLonHon(const void* x,const void* y)
{
	if(*(int*)x > *(int*)y)
		return 1;
	else if(*(int*)x == *(int*)y)
		return 0;
	else 
		return -1;
}
int main()
{
	int n = 10000;
	int* a = NULL;
	a = new int[n];
	TaoNgauNhien(a, n);
	qsort(a, n, sizeof(int), SoSanhLonHon);
	XuatMang(a, n);


	if(a != NULL)
		delete []a;
	system("pause");
	return 0;
}