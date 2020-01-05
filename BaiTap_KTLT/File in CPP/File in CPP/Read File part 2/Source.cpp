#include <fstream>
#include <iostream>
#include <string>
using namespace std;
struct SINHVIEN
{
	string MSSV, Hoten, NamSinh, QueQuan;
};

void Xuat(const SINHVIEN sv)
{
	cout<<sv.MSSV<<endl;
	cout<<sv.Hoten<<endl;
	cout<<sv.NamSinh<<endl;
	cout<<sv.QueQuan<<endl;
}
int main()
{
	ifstream Infile;
	Infile.open("TTSV.dat",ios::in);

	if(Infile.is_open() == false)
	{
		cout<<"Ko the mo tap tin";
		system("pause");
		return 0;
	}
	SINHVIEN List[10];
	int dem = 0;
	while(getline(Infile, List[dem].MSSV, '|'))
	{
		getline(Infile, List[dem].Hoten, '|');
		getline(Infile, List[dem].NamSinh, '|');
		getline(Infile, List[dem].QueQuan, '|');
		dem++;
	}
	Infile.close();

	for(int i = 0; i < dem; i++)
	{
		cout<<"Sinh vien thu "<<i+1<<"\n";
		Xuat(List[i]);
	}
	system("pause");
	return 0;
}