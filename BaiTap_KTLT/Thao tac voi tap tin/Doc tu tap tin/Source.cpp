#include <fstream>
#include <iostream>
using namespace std;

void InterchangeSort(int* a, int n)
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(a[i] > a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
int main()
{
	// Đối với thao tác đọc tập tin thì chúng ta phải tạo ra tập tin trước
	ifstream Infile;
	Infile.open("text.txt", ios::in);    // Mở tập tin với đối số mode là in

	if(Infile.is_open() == false)      // Nếu như mở tập tin thất bại
	{
		cout<<"Khong the mo tap tin de doc!";
		system("pause");
		return 0;
	}
	int *a = NULL;
	int n;
	Infile>>n;
	a = new int [n];
	for(int i = 0; i < n; i++)
	{
		Infile>>a[i];
	}
	//while(Infile>>a[n])       //Nếu file không cho n thì dùng cách này. Khi còn đọc được dữ liệu.
	//{
	//	n++;
	//}
	Infile.close();
	InterchangeSort(a, n);  // Gọi hàm sắp xếp mảng

	ofstream Outfile;
	Outfile.open("KETQUA.txt", ios::out);

	for(int i = 0; i < n; i++)
	{
		Outfile<<a[i]<<" ";
	}
	Outfile.close();

	if( a != NULL)
		delete []a;
	system("pause");
	return 0;
}