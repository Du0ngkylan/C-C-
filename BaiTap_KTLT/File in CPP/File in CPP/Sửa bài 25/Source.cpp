#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct SINHVIEN
{
	string Hoten, MSSV,Lop;
	float DTB;
};

void Xuat(SINHVIEN sv, ofstream& Out)
{
	Out<<"Ho ten: "<<sv.Hoten<<endl;
	Out<<"MSSV: "<<sv.MSSV<<endl;
	Out<<"Lop: "<<sv.Lop<<endl;
	Out<<"DTB: "<<sv.DTB<<endl<<endl;
}
void Xuat(SINHVIEN sv)
{
	cout<<"Ho ten: "<<sv.Hoten<<endl;
	cout<<"MSSV: "<<sv.MSSV<<endl;
	cout<<"Lop: "<<sv.Lop<<endl;
	cout<<"DTB: "<<sv.DTB<<endl<<endl;
}
int main()
{
	
	SINHVIEN a[3];

	ifstream Infile("sv.txt");
	if(Infile.is_open() == false)
	{
		return 0;
	}
	 
	int n = 0;
	while(Infile.eof() == false)
	{
		getline(Infile,a[n].Hoten);
		getline(Infile, a[n].MSSV);
		getline(Infile, a[n].Lop);
		Infile>>a[n].DTB;
		
		n++;
	}
	Infile.close();
	for(int i = 0; i < n; i++)
	{
		Xuat(a[i]);
	}



























	/*a[0].MSSV = "1";
	a[1].MSSV = "2";
	a[2].MSSV = "3";
	a[0].Hoten = "Nguyen Ai Tuan";
	a[1].Hoten = "Huynh Phi Hung";
	a[2].Hoten = "Truong Thai An";
	a[0].Lop = "13DTH01";
	a[1].Lop = "13DTH02";
	a[2].Lop = "13DTH03";
	a[0].DTB = 6;
	a[1].DTB = 7;
	a[2].DTB = 8;
    */
	/*ofstream Outfile("sinhvien.txt");

	Xuat(a[0], Outfile);
	Xuat(a[1], Outfile);
	Xuat(a[2], Outfile);

	Outfile.close();*/
	system("pause");
	return 0;
}
