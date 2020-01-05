#include <iostream>
using namespace std;

template <class T>
void NhapMang(T* a, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout<<"Nhap a["<<i<<"]:\n";
		cin>>a[i];
	}
}

template<class T>
void XuatMang(T* a, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout<<a[i]<<"\t";
	}
}
int main()
{
	int n = 5;
	char* a = NULL;
	a = new char [n];
	// Gọi hàm tường minh
	//NhapMang<float>(a, n);
	NhapMang(a , n);

	// Gọi hàm ko tường minh
	XuatMang(a, n);
	system("pause");

	if(a != NULL)
		delete []a;
	return 0;
}
