#include <iostream>
#include <ctime>
using namespace std;
bool KiemTraTrung(int a[],int n, int vitrikiemtra);
void NhapMang(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout<<"Nhap a["<<i<<"]:\n";
		cin>>a[i];
	}
}
void NhapMangKhongTrung(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		do
		{
		cout<<"Nhap a["<<i<<"]:\n";
		cin>>a[i];
		if(KiemTraTrung(a, n, i) == true)
			cout<<"Gia tri nay da co trong mang. Vui long nhap lai hehe!\n";
		}while(KiemTraTrung(a, n, i));
	}
}
void TaoNgauNhien(int a[], int n)
{
	srand(time(0));
	for(int i = 0; i < n; i++)
	{
		a[i] = rand()%10 + 1;
	}
}

void XuatMang(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d\t",i[a]);
	}
}
void XoaPhanTu(int a[], int& n, int vitrixoa)
{
	  for(int i = vitrixoa; i < n - 1; i++)
	  {
		  a[i] = a[i + 1];
	  }
	  n--;
}
void ThemPhanTu(int a[], int& n, int vitrithem, int giatrithem)
{
	for(int i = n; i > vitrithem; i--)
	{
		a[i] = a[i-1];
	}
	a[vitrithem] = giatrithem;
	n++;
}

void XoaPhanTux(int a[], int&n, int x)
{
	for(int i = 0; i < n; i++)
	{
		if(a[i] == x)
		{
			XoaPhanTu(a, n, i);
			i--;
		}
	}
}
void XoaPhanTuTaiVitrile(int a[], int& n)
{
	bool check = true;
	for(int i = 0; i < n; i++)
	{

		if(i % 2 != 0 && check == true)
		{
			XoaPhanTu(a, n, i);
			check = false;
		}
		if(i % 2 == 0 && check == false)
		{
			XoaPhanTu(a, n, i);
			check = true;
		}
	}
}
bool KiemTraTrung(int a[],int n, int vitrikiemtra)
{
	for(int i = 0; i < vitrikiemtra; i++)
	{
		if(a[i] == a[vitrikiemtra])
		{
			return true;
		}
	}
	return false;
}
// SelectionSort
// QuickSort
void InterchangeSort(int a[], int n)    // Sắp xếp tăng dần
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			// Hoán vị khi thằng a[i] > a[j])
			if(a[i] > a[j])
			swap(a[i], a[j]);
		}
	}
}

//void SapTangDanNguyenTo(int a[], int n)
//{
//	for(int i = 0; i < n - 1; i++)
//	{
//		for(int j = i + 1; j < n; j++)
//		{
//			// Hoán vị khi thằng a[i] > a[j]
//			if(KiemTraNguyenTo(a[i]) && KiemTraNguyenTo(a[j))
//			{
//			  if(a[i] > a[j])
//			  swap(a[i], a[j]);
//			}
//		}
//	}
//}


void main()
{
	int n = 10;
	int a[50];
	//NhapMang(a, n);
	//TaoNgauNhien(a, n);
	NhapMangKhongTrung(a, n);
	XuatMang(a,n);
	//XoaPhanTu(a, n, 1);
	//ThemPhanTu(a, n, 1, 100);
	int x = 10;
	//XoaPhanTux(a, n, x);
	//XoaPhanTuTaiVitrile(a, n);
	InterchangeSort(a, n);
	cout<<"\n";
	XuatMang(a,n);
	system("pause");
}