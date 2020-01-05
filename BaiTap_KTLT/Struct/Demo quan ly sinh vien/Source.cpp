#include <iostream>
#include <string>
#include <vector>        // Thư viện hỗ trợ tạo mảng động
using namespace std;

struct SINHVIEN
{
    string MSSV;
    string HoTen;
    string NTNS;
    bool GioiTinh;
    float DToan, DLy, DHoa;
};
// tạo ra 2 hàm  nhập, xuất

void NhapSINHVIEN(SINHVIEN& sv)
{
	fflush(stdin);
	// Nhập thông tin cho sv1
	cout<<"Nhap MSSV:\n";
	getline(cin,sv.MSSV);      
	cout<<"Nhap Ho ten:\n";
	getline(cin, sv.HoTen);
	cout<<"Nhap NTNS:\n";
	getline(cin, sv.NTNS);
	cout<<"Nhap gioi tinh (1: Nam, 0: Nu)\n";
	cin>>(sv.GioiTinh);
	cout<<"Nhap diem toan, ly, hoa:\n";
	cin>>sv.DToan>>sv.DLy>>sv.DHoa;
}
void XuatSINHVIEN(const SINHVIEN sv)
{
	// Xem thông tin của sv1
	cout<<"MSSV: "<<sv.MSSV<<endl;
	cout<<"Ho ten: "<<sv.HoTen<<endl;
	cout<<"NTNS: "<<sv.NTNS<<endl;
	if((sv.GioiTinh) == true)
	cout<<"Gioi tinh: Nam"<<endl;
	else 
		cout<<"Gioi tinh: Nu"<<endl;
	cout<<"Diem toan: "<<sv.DToan<<", diem ly: "<<sv.DLy<<", diem hoa: "<<sv.DHoa<<endl;
}
struct QUANLYSINHVIEN 
{
	vector<SINHVIEN> a;
};

void XuatDanhSachSV(const vector<SINHVIEN> a)
{
	for(int i = 0; i < a.size(); i++)
	{
		cout<<"Xuat Sinh Vien Thu "<<i+1<<endl;
		XuatSINHVIEN(a[i]);
		cout<<endl;
	}
}
void XoaSinhVienYeu(vector<SINHVIEN>& a)
{
	for(int i = 0; i < a.size(); i++)
	{
		float DTB = (a[i].DHoa + a[i].DLy + a[i].DToan) / 3;
		if(DTB < 3)
		{
			a.erase(a.begin() + i);       // Phương thức erase để xóa phần tử trong 1 vector
			i--;
		}
	}
}
void STRINGUPPER(string& s)
{
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] -= 32;
		}
	}
}

void InHoaTenSinhVien(vector<SINHVIEN>& a)
{
	for(int i = 0; i < a.size(); i++)
	{
		STRINGUPPER(a[i].HoTen);
	}
}
float TinhDiemTB(float dtoan, float dly, float dhoa)
{
	return (dtoan + dly + dhoa) / 3;
}
void InterchangeSort(vector<SINHVIEN>& a)
{
	for(int i = 0; i < a.size() - 1; i++)
	{
		for(int j = i + 1; j < a.size(); j++)
		{
			float DTB1 = TinhDiemTB(a[i].DToan, a[i].DLy, a[i].DHoa);
			float DTB2 = TinhDiemTB(a[j].DToan, a[j].DLy, a[j].DHoa) ;
			if(DTB1 < DTB2)
			{
				swap(a[i], a[j]);
			}
		}
	}
}
int main()
{
	int chon;
	QUANLYSINHVIEN QLSV;
	do 
	{
		system("cls");
		cout<<"0.Thoat\n\n";
		cout<<"1.Them Sinh Vien\n\n";
		cout<<"2.Xuat Danh Sach Sinh Vien\n\n";
		cout<<"3.Xoa Sinh Vien Diem TB < 3\n\n";
		cout<<"4.IN HOA Ten Sinh Vien\n\n";
		cout<<"5.Sap Xep Danh Sach Giam Dan Theo DTB\n\n";
		cout<<"6.Xoa Tat Ca Sinh Vien\n\n";
		cout<<"Moi ban chon menu:\n";
		cin>>chon;
		switch (chon)
		{
		case 0:break;
		case 1:
			{
				SINHVIEN sv;
				NhapSINHVIEN(sv);
				QLSV.a.push_back(sv);
				break;
			}
		case 2:
			{
				XuatDanhSachSV(QLSV.a);
				system("pause");
				break;
			}
		case 3:
			{
				XoaSinhVienYeu(QLSV.a);
				XuatDanhSachSV(QLSV.a);
				system("pause");
				break;
			}
		case 4:
			{
				InHoaTenSinhVien(QLSV.a);
				break;
			}
		case 5:
			{
				InterchangeSort(QLSV.a);
				break;
			}
		case 6:
			{
				QLSV.a.clear();
				break;
			}
		default:
			break;
		}
	}while(chon != 0);
	system("pause");
	return 0;
}