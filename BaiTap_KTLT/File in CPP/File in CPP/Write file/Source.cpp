#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	ifstream Infile;
	Infile.open("BaiHat.txt", ios::in);
	if(!Infile.is_open())
	{
		cout<<"Ko the mo tap tin de doc!\n";
		system("pause");
		return 0;
	}
	int demtu = 0;
	string s;
	while(Infile>>s)
	{
		demtu++;
	}
	Infile.close();
    ofstream Outfile;
	Outfile.open("MyDoc.txt", ios::out);
	if(Outfile.is_open() == false)
	{
		cout<<"Ko the mo tap tin de ghi!";
		system("pause");
		return 0;
	}
	Outfile<<"So tu trong bai hat Happy new year la "<<demtu;
	Outfile.close();
	return 0;
}