#include <iostream>
#include <string>
using namespace std;
struct SINHVIEN
{
    string MSSV;
    string HoTen;
    string NTNS;
    bool GioiTinh;
    float DToan, DLy, DHoa;
};

void NhapSINHVIEN(SINHVIEN& sv)
{
	fflush(stdin);
	cout<<"Nhap MSSV:\n";
	getline(cin, sv.MSSV);
	cout<<"Nhap Ho Ten:\n";
	getline(cin, sv.HoTen);
	cout<<"Nhap Ngay Thang Nam Sinh:\n";
	getline(cin, sv.NTNS);
	cout<<"Nhap gioi tinh(1 la Nam/ 0 la Nu)\n\n";
	cin>>sv.GioiTinh; 
	do 
	{
		cout<<"Nhap dtoan, dly, dhoa:\n";
		cin>>sv.DToan>>sv.DLy>>sv.DHoa;
		if(sv.DHoa < 0 || sv.DHoa > 10 || sv.DLy < 0 || sv.DLy > 10 || sv.DToan < 0 || sv.DToan > 10)
			cout<<"Du lieu khong hop le. Nhap lai!\n";
	}while(sv.DHoa < 0 || sv.DHoa > 10 || sv.DLy < 0 || sv.DLy > 10 || sv.DToan < 0 || sv.DToan > 10);
}
void XuatSINHVIEN(SINHVIEN sv)
{
	cout<<"MSSV: "<<sv.MSSV<<endl;
	cout<<"Ho ten: "<<sv.HoTen<<endl;
	cout<<"NTNS: "<<sv.NTNS<<endl;
	if(sv.GioiTinh != 0)
	cout<<"Gioi tinh: Nam"<<endl;
	else 
	cout<<"Gioi tinh: Nu"<<endl;
	cout<<"Dtoan: "<<sv.DToan<<endl;
	cout<<"Dly: "<<sv.DLy<<endl;
	cout<<"Dhoa: "<<sv.DHoa<<endl<<endl;
}

struct QUANLYSINHVIEN 
{
	SINHVIEN* list;
	int n;
};

void NhapDanhSach(QUANLYSINHVIEN& QLSV, int pn)
{
	QLSV.list = new SINHVIEN[pn];
	QLSV.n = pn;
	for(int i = 0; i < QLSV.n; i++)
	{
		cout<<"Nhap sinh vien thu "<<i+1<<endl;
		NhapSINHVIEN(QLSV.list[i]);
	}
}
void XuatDanhSach(QUANLYSINHVIEN QLSV)
{
	for(int i = 0; i < QLSV.n; i++)
	{
		cout<<"Xuat sinh vien thu "<<i+1<<endl;
		XuatSINHVIEN(QLSV.list[i]);
	}
}
float TinhDTB(SINHVIEN sv)
{
	return (sv.DToan + sv.DLy  + sv.DHoa) / 3;
}

SINHVIEN TimSVDTBMax(QUANLYSINHVIEN QLSV)
{
	SINHVIEN SvDTBMAX = QLSV.list[0];           
	float DTBMAX = TinhDTB(QLSV.list[0]);
	for(int i = 1; i < QLSV.n; i++)
	{
		if(TinhDTB(QLSV.list[i])  > DTBMAX)
		{
			SvDTBMAX = QLSV.list[i];
			DTBMAX = TinhDTB(QLSV.list[i]);
		}
	}
		return SvDTBMAX;
}
int main()
{
	int n = 0;
	QUANLYSINHVIEN QLSV;
	QLSV.list = NULL;             // Mặc định cho con trỏ list = NULL và số lượng n = 0
	QLSV.n = 0;
	int chon;
	do 
	{
		system("cls");
		cout<<"0. Thoat\n\n";
		cout<<"1. Nhap Danh Sach SV\n\n";
		cout<<"2. Xuat Danh Sach SV\n\n";
		cout<<"3. Tim SV Diem TB Max\n\n";
		cout<<"Moi ban chon menu:\n";
		cin>>chon;
		switch (chon)
		{
		case 0:break;
		case 1:
			{
				    do 
	             {
	                cout<<"Nhap so luong sinh vien:\n";
		            cin>>n;
		               if(n < 0)
			         cout<<"So luong khong hop le. Nhap lai!\n";
	              }while(n < 0);
				 NhapDanhSach(QLSV, n);                         
				 break;
			}
		case 2: XuatDanhSach(QLSV); system("pause"); break;
		case 3:
			{
				if(QLSV.n == 0)             // Nếu ko có sinh viên nào thì ko làm case này được
					break;
				SINHVIEN SVDTBMax = TimSVDTBMax(QLSV);
	            cout<<"Sinh vien co diem trung binh lon nhat la: "<<endl;
	            XuatSINHVIEN(SVDTBMax);
	            system("pause");
				break;
			}
		default:
			break;
		}
	}while(chon != 0);

	if(QLSV.list != NULL)
		delete []QLSV.list;
	return 0;
}