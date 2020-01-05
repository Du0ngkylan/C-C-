#include <iostream>    // input output stream
using namespace std;

void NhapSoNguyen(int& n)
{
	cout<<"Nhap vao n:\n";
	cin>>n;
}

int TinhTong(int a, int b)
{
	return a + b;
}
int TinhHieu(int a, int b)
{
	return a - b;
}

void main()
{
	int a, b;
	void (*q)(int& );
	q = NhapSoNguyen;
	q(a);  // Nhập a
	q(b); // Nhập b
	// Khai báo con trỏ hàm
	int (*p)(int, int);
	p = TinhTong;  // p đang trỏ đến ô nhớ của hàm TinhHieu

	cout<<p(a, b);   // Xuất 
	system("pause"); // Dừng màn hình
}