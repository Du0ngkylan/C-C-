#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	
	ifstream Infile;
	string Filename;
	cout<<"Nhap file muon doc:\n";
	getline(cin, Filename);
	
	Infile.open(Filename,ios::in);
	if(Infile.is_open() == false)
	{
		cout<<"Ko the mo tap tin de doc!";
		cin.get();
		return 0;
	}
	int dem = 0;
	string Tu, s;
	cout<<"Nhap tu can dem:\n";
	getline(cin, Tu);
	
	while(Infile>>s)
	{	
		if(s == Tu)
			dem++;
	}
	Infile.close();


	ofstream Outfile("KETQUA.txt", ios::out);
	
	Outfile<<"Tu "<<Tu<<" xuat hien trong file "<<Filename<<" "<<dem<<" lan";
	Outfile.close();

	system("pause");
	return 0;
}