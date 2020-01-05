#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	// THỰC HIỆN ĐỌC TẬP TIN 
	ifstream Infile;
	Infile.open("Text.txt",ios::in);

	if(Infile.is_open() == false)
	{
		cout<<"Ko the mo tap tin de doc!";
		cin.get();
		return 0;
	}
	int dem = 0;
	char c;
	while(Infile>>c) // Khi còn hứng được ký tự từ tập tin bỏ vô biến c
	{
		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			dem++;
	}
	Infile.close();
	
	// THỰC HIỆN GHI KẾT QUA dem ra tập tin khác
	ofstream Outfile;
	Outfile.open("KETQUA.txt", ios::out);
	Outfile<<dem;

	Outfile.close();
	
	return 0;
}