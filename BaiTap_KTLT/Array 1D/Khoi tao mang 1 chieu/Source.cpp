#include <iostream> // input output stream 
                     // Khai báo namespace (tên miền) std (standard) của C++
using namespace std; 


int main()
{
	// Khởi tạo xác định số lượng phần tử
	//int a[5] = {1, 2, 3, 4, 5};

	// Khởi tạo ko cần xác định số lượng phần tử
	int b[] = {1, 0, 5, 2, 7, 0 , 5, 0}; 
	int sizeb = sizeof(b) / sizeof(int); // 32 / 4 = 8

	// Xuất ra phần tử tại chỉ số thứ 6
	cout<<"phan tu b[6] = "<<b[6];

	system("pause");     // Hàm dừng màn hình
	return 0;
}

