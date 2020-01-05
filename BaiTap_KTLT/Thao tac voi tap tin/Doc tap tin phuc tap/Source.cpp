#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct SINHVIEN 
{
	string  MSSV, Hoten, SODT, Gioitinh;
	float Diemtb;
};

void XuatSinhVien(SINHVIEN sv, ofstream& Outfile)
{
	Outfile<<"MSSV: "<<sv.MSSV<<endl;
	Outfile<<"Ho ten: "<<sv.Hoten<<endl;
	Outfile<<"So dien thoai: "<<sv.SODT<<endl;
	Outfile<<"Gioi tinh: "<<sv.Gioitinh<<endl;
	Outfile<<"Diem tb: "<<sv.Diemtb<<endl<<endl;
}
int main()
{
	ifstream Infile("SINHVIEN.txt", ios::in);

	if(Infile.is_open() == false)
	{
		cout<<"Khong the mo tap tin de doc";
		system("pause");
		return 0;
	}
	SINHVIEN List[10];
	int n = 0;
	while(getline(Infile, List[n].MSSV,'|'))
	{
		getline(Infile, List[n].Hoten,'|');
		getline(Infile, List[n].SODT,'|');
		getline(Infile, List[n].Gioitinh,'|');
		Infile>>List[n].Diemtb;
		n++;
	}
	Infile.close();

	ofstream Outfile;
	string FileLuu;
	fflush(stdin);
	cout<<"Nhap noi can luu:\n";
	getline(cin, FileLuu);           // Cho người dùng tùy ý chọn nơi lưu tập tin
	Outfile.open(FileLuu, ios::out); 
	for(int i = 0; i < n; i++)
	{
		XuatSinhVien(List[i], Outfile);
	}
	Outfile.close();
	system("pause");
	return 0;
}