#include <iostream>
using namespace std;

void main()
{
	char so[10];
	cout<<"Nhap vao so:\n";
	gets_s(so); 
	int x = atoi(so);       //Sử dụng atoi
	cout<<"x = "<<x;

	// Sử dụng itoa
	int y = 153848;
	_itoa_s(y, so, 10);
	cout<<endl<<"so "<<so;
	system("pause");
}