#include <iostream>
using namespace std;

template<class T>     // T là tên kiểu dữ liệu trừu tượng. Các bạn có thể đặt tên khác
void HoanVi(T& x, T& y)
{
	T temp = x;
	x = y;
	y = temp;
}


int main()
{
	float x = 6.8, y = 6.9;
	// 2 cách để gọi 1 hàm được tham số hóa
	//HoanVi<char>(x, y);     // Cách gọi hàm tường minh


	HoanVi(x, y);            // Cách gọi hàm không tường mình
	cout<<x<<" "<<y;
	system("pause");
	return 0;
}
