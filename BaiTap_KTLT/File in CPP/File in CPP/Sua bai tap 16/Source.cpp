#include <iostream>
#include <fstream>
using namespace std;

int SoSanhLonHon(const void* x, const void* y)
{
	if(*(int*)x > *(int*) y )
		return 1;
	else if(*(int*)x == *(int*)y)
	    return 0;
	else 
		return -1;
}

void XuatMang(int* a, int n, ofstream& Out)
{
	for(int i = 0; i < n; i++)
	{
		Out<<a[i]<<" ";
	}
}
int main()
{
	int n = 0;
	int* a = NULL;
	ifstream Infile;
	Infile.open("Array.txt",ios::in);

	if(Infile.is_open() == false)
	{
		cout<<"Ko the mo tap tin de doc!";
		cin.get();
		return 0;
	}
	Infile>>n;
	a = new int[n];
	for(int i = 0; i < n; i++)
	{
		Infile>>a[i];
	}
	Infile.close();
	qsort(a, n, sizeof(int), SoSanhLonHon);

	ofstream Outfile;
	Outfile.open("KETQUA.txt", ios::out);
	Outfile<<n<<endl;
	XuatMang(a, n, Outfile);
	Outfile.close();
	if(a != NULL)
		delete []a;
	return 0;
}