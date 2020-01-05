#include <iostream>
using namespace std;

int TinhTong(int x, int y)
{
	return x + y;
}

int main()
{
	// Để 1 con trỏ có thể trỏ đến 1 hàm nào đó. Thì con trỏ hàm phải có cùng signature với hàm đó.
	int (*p)(int , int );

	// Có 2 cách cho con trỏ hàm trỏ đến 1 hàm
	p = &TinhTong;
	//p = TinhTong;
	cout<<p(1, 2);
	system("pause");
	return 0;
}