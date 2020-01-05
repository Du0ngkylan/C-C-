#include <iostream>
using namespace std;

void main()
{
	int x = 1;
	cout<<&x;
	int* pointer = NULL; 
	pointer = &x;

	// Toán tử * để lấy ra giá trị mà con trỏ đang trỏ đến
	cout<<endl<<*pointer;
	// Ko để toán tử gì cả thì lấy ra địa chỉ mà con trỏ đang trỏ đến
	cout<<endl<<pointer;

	// Nếu để cả dấu & trước tên con trỏ thì ta đang lấy ra "địa chỉ của riêng" con trỏ.
	cout<<endl<<&pointer;
	system("pause");
}