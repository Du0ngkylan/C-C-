#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string TenfileDoc;
	cout<<"Nhap file muon doc:\n";
	getline(cin, TenfileDoc);

	ifstream Infile(TenfileDoc, ios::in);
	if(Infile.fail())
	{
		cout<<"Mo tap tin de doc that bai!";
		cin.get();
		return 0;
	}
	int demtu = 0;
	string Tu;
	while(Infile>>Tu)
	{
		demtu++;
	}
	cout<<demtu;
	Infile.close();

	cin.get();
	return 0;
}