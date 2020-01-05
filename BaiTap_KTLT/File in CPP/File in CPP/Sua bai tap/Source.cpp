#include <iostream>
#include <fstream>
using namespace std;

void GiaiPTBac2(float a, float b, float c, ofstream& Outfile)
{
	if(a == 0 )
	{
		if(b == 0)
		{
			if(c == 0)
			{
				Outfile<<"PT VSN";
			}
			else 
				Outfile<<"PT VN";
		}
		else 
		{
			float x = -c / b;
			Outfile<<"PT CO NGHIEM KEP X1 = X2 = "<<x;
		}
	}
	else 
	{
		double delta = b * b - 4 *a * c;
		if(delta < 0)
			Outfile<<"PT VN";
		else if(delta == 0)
		{
			float x = -b / (2 * a);
			Outfile<<"PT CO NGHIEM KEP X1 = X2 = "<<x;
		}
		else 
		{
			float x1 = (-b +  sqrt(delta)) / (2 * a);
			float x2 = (-b -  sqrt(delta)) / (2 * a);
			Outfile<<"PT CO 2 NGHIEM X1 = "<<x1<<", X2 = "<<x2;
		}
	}	
}
int main()
{
	ifstream Infile;
	Infile.open("MyDoc.txt", ios::in);
	if(Infile.is_open() == false)
	{
		cout<<"Ko the mo tap tin de doc!";
		cin.get();
		return 0;
	}
	float a, b , c;
	Infile>>a>>b>>c;
	Infile.close();

	ofstream Outfile;
	Outfile.open("KETQUA.txt", ios::out);
	
	GiaiPTBac2(a, b, c, Outfile);
	Outfile.close();
}

