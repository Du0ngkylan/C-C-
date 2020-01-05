#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	ifstream Infile("text2.txt");
	ofstream Outfile("text1.txt", ios::app);
	if(Infile.is_open() == false)
	{
		cout<<"Mo tap tin de doc that bai!\n";
		cin.get();
		return 0;
	}
	char c;
	while(Infile.get(c))
	{
		Outfile.put(c);
	}
	Infile.close();
	Outfile.close();
	system("pause");
	return 0;
}
