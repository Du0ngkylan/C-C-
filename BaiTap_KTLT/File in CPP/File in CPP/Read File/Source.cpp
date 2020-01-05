#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	ifstream Infile;
	Infile.open("MyDoc.txt",ios::in);

	if(Infile.is_open() == false)
	{
		cout<<"Ko the mo tap tin";
		system("pause");
		return 0;
	}
	string hoten[10];
	int dem = 0;
	while(getline(Infile, hoten[dem]))
	{
		dem++;
	}
	for(int i = 0; i < dem; i++)
	{
		cout<<"Ten thu "<<i+1<<": "<<hoten[i]<<endl;
	}
	Infile.close();
	system("pause");
	return 0;
}