#include <iostream>
#include <ctime>            
using namespace std;

void TaoNgauNhien(int a[], int n)
{
	srand(time(0));                // second random 
	//1. Nếu muốn random 1 số bất kỳ thì chỉ việc để a[i] = rand();
	//2. Nếu muốn random 1 số trong khoảng từ a đến b thì a[i] = rand()%b + a;
	for(int i = 0; i < n; i++)
	{
		a[i] = rand()%10 + 1;
	}
}
void NhapMang(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout<<"Nhap a["<<i<<"]:\n";
		cin>>a[i];
	}
}
void XuatMang(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d\t",i[a]);
	}
}
void XoaPhanTu(int a[],int& n, int vitrixoa)
{
	for(int i = vitrixoa; i < n; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
void ThemPhanTu(int a[],int& n, int vitrithem, int giatrithem)
{
	for(int i = n; i > vitrithem; i--)
	{
		a[i] = a[i - 1];
	}
	a[vitrithem] = giatrithem;
	n++;
}
void XoaPhanTux(int a[],int& n,int x)
{
	for(int i = 0; i < n; i++)
	{
		if(a[i] == x)
		{
			XoaPhanTu(a, n, i);
			i--;          // Tại sao lại phải có thêm  i--? ^^
		}
	}
}
//144.	Viết chương trình chèn phần tử có giá trị X vào phía sau phần tử có giá trị lớn nhất trong mảng.
// 8 5 3 9 9 2 0 9 1
// x = 100
// 8 5 3 9 100 9 100 2 0 9 100 1
int Timmax(int a[], int n)			
{
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return max;
}
void ChenxVaoSauPhanTuMax(int a[], int& n, int x)
{
	int max = Timmax(a, n);
	for(int i = 0; i < n; i++)
	{
		if(a[i] == max)
		{
			ThemPhanTu(a, n, i + 1, x);
			i++;
		}
	}
}

void main()
{
	int n = 5;
	int a[50];
	NhapMang(a, n);
	//TaoNgauNhien(a, n);
	XuatMang(a, n);
	//XoaPhanTu(a, n , 3);
	int b;
	cout<<"Moi ban nhap x:\n";
	cin>>b;
	//XoaPhanTux(a, n, b);
	ChenxVaoSauPhanTuMax(a, n, b);
	XuatMang(a, n);
	system("pause");
}