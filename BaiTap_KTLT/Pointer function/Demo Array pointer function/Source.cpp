#include <iostream>
using namespace std;

template <class T>
T TinhTong(T x, T y)
{
	return x + y;
}

template <class T>
T TinhHieu(T x, T y)
{
	return x - y;
}
template <class T>
T TinhTich(T x, T y)
{
	return x * y;
}

template <class T>
T TinhThuong(T x, T y)
{
	if(y == 0)
	{
		return x;
	}
	return x / y;
}
int main()
{
	// Khai báo 1 mảng 4 con trỏ hàm
	float (*p[4])(float , float );
	p[0] = TinhTong;
	p[1] = TinhHieu;
	p[2] = TinhTich;
	p[3] = TinhThuong;
	for(int i = 0; i < 4; i++)
	{
		cout<<endl<<p[i](1, 2);
	}
	system("pause");
	return 0;
}