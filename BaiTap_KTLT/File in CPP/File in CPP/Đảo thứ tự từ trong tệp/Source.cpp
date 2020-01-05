#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	ifstream Infile("demo.txt", ios::in);
	string ArrayTu[100];
	int n = 0;

	while(Infile>>ArrayTu[n])
	{
		n++;
	}
	Infile.close();

	ofstream Outfile("ketqua.txt", ios::out);

	for(int i = n - 1; i >= 0; i--)
	{
		Outfile<<ArrayTu[i]<<" ";
	}
	Outfile.close();
	system("pause");
	return 0;
}