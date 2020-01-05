#include <fstream>        // Include đến thư viện file stream
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string hoten;
	unsigned int tuoi;

	cout<<"Nhap ho ten cua ban:\n";
	getline(cin, hoten);
	cout<<"Nhap tuoi:\n";
	cin>>tuoi;

	ofstream Outfile;
	Outfile.open("MyDoc.txt", ios::out);
	Outfile<<hoten<<endl<<tuoi; 
	Outfile.close();
	system("pause");
	return 0;
}