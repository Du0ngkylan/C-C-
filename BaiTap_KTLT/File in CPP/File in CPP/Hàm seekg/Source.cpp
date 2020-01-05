#include <iostream>
#include <fstream>
using namespace std;


struct POINT
{
	int x, y;
};

void Xuat(const POINT p)
{
	cout<<"("<<p.x<<","<<p.y<<")";
}

int main()
{
	POINT* a = NULL;
	
	ifstream Infile("DSDIEM.txt");
	int n;
	Infile>>n;
	a = new POINT[n];
	for(int i = 0; i < n; i++)
	{
		Infile.seekg(1, SEEK_CUR);
		Infile>>a[i].x;
		Infile.seekg(1, SEEK_CUR);
		Infile>>a[i].y;
		Infile.seekg(1, SEEK_CUR);
	}

	for(int i = 0; i < n; i++)
		Xuat(a[i]);
	Infile.close();

	if(a != NULL)
		delete []a;
	cin.get();
	return 0;
}