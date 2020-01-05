#include <iostream>
#include <string>
using namespace std;

/* template function */

template <class T>
void NhapMang(T* a, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout<<"Nhap vao a["<<i<<"]:\n";
		cin>>a[i];
	}
}

template <class T>
void XuatMang(T* a, int n)
{
	for(int i = 0; i  < n; i++)
	{
		cout<<a[i]<<"\t";
	}
}
template <class T>             // Hàm này đã được tham số hòa bằng kỹ thuật template 
void HoanVi(T &x, T &y)
{
	T temp = x;
	x = y;
	y = temp;
}

template <class T>
void InterchangeSort(T *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(a[i] > a[j])
			{
				HoanVi(a[i], a[j]);
			}
		}
	}
}
void main()
{
	int n = 5;
	string *a = new string[n];
	
	NhapMang(a,n);
	InterchangeSort(a, 5);
	XuatMang(a, 5);
	delete []a;
	system("pause");
}