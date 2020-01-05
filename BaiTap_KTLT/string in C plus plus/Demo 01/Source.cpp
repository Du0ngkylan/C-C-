#include <iostream>
#include <string>
using namespace std;

int main()
{
	string hodem, ten;
	//int x;
	//cin>>x;// 20 ENTER
	//fflush(stdin); // Xóa đi bộ nhớ đệm 
	cout<<"Nhap ho dem:\n";
	getline(cin, hodem);  // Nhập chuỗi dùng phương thức getline
	cout<<"Nhap ten:\n";
	getline(cin, ten);

	string hoten = hodem +   ten;

	cout<<endl<<hoten;
	system("pause");
	return 0;
}