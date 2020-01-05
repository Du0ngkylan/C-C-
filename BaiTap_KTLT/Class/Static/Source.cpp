#include <iostream>
using namespace std;

class Test 
{
	int dem;   // Thuộc tính member của Test
	static int demtinh;  // Thuộc tính static của Test
public:
	Test()
	{
		dem = 0;
	}
	void Tang()
	{
		dem++;
		demtinh++;
	}
	void Show()
	{
		cout<<dem<<endl;
		cout<<demtinh<<endl;
	}
};

int Test::demtinh = 0;

void main()
{
	Test a;
	a.Tang();
	a.Show();

	Test b;  // dem = 0 . demtinh = 1
	b.Tang();  // dem = 1.demtinh = 2
	b.Show();

	Test c;  // dem = 0, demtinh = 2
	c.Tang(); // dem = 1, demtinh = 3
	c.Show();
	//
	cin.get();
}