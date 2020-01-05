#include <iostream>
#include <string.h>
using namespace std;


void main()
{
	char hoten[30];   // Khai báo chuỗi họ tên gồm tối đa 29 ký tự có thể nhập
    cout<<"MOI BAN NHAP HO TEN:";
	//fflush(stdin);         // Xóa đi bộ nhớ đệm
	gets_s(hoten);
	char diachi[30];
	//strcpy(diachi, hoten);    // Hàm để sao chép ký tự
	int len = strlen(hoten);
	strcpy_s(hoten, 30,_strrev(hoten));
	//strcpy(hoten, strupr(hoten));
	cout<<"Ho ten cua ban la "<<hoten<<endl;
	cout<<"Do dai ten cua ban la "<<len;
	system("pause");
}