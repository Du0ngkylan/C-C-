#include <iostream>
using namespace std;

void NhapMang1Chieu(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
}
void XuatMang2Chieu(int a[][10], int sodong, int socot)
{
	for(int i = 0; i < sodong; i++)
	{
		for(int j = 0; j < socot; j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}
}
void main()
{
	int a[10][10];
	int sodong = 3, socot = 3;

	NhapMang1Chieu(a[0], socot);
	NhapMang1Chieu(a[1], socot);
	NhapMang1Chieu(a[2], socot);
	XuatMang2Chieu(a, sodong, socot);
	system("pause");
}