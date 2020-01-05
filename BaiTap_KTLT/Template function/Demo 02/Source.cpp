#include <iostream>
#include <string>
using namespace std;

template <class T, class Y>
void NhapSo(T& a, Y& b)
{
	cout<<"Nhap a:\n";
	cin>>a;
	cout<<"Nhap b:\n";
	cin>>b;
}

template <class T, class Y>
void XuatSo(T& a, Y& b)
{
	cout<<a<<" "<<b;
}

int main()
{
	float x;
	char y;
	NhapSo(x, y);
	XuatSo(x, y);
	system("pause");
	return 0;
}