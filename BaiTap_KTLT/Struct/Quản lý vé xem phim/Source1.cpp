#include <iostream>
#include <string>
#include <vector>      // Thư viện hỗ trợ tạo lập và thao tác trên mảng động
using namespace std;

struct THOIGIAN 
{
	unsigned short Gio, Phut;
};

void NhapTHOIGIAN(THOIGIAN& tg)
{
	do 
	{
		cout<<"Nhap gio:\n";
		cin>>tg.Gio;
		if(tg.Gio < 0 || tg.Gio > 23)
			cout<<"So gio khong hop le. Nhap lai";
	}while(tg.Gio < 0 || tg.Gio > 23);
	do 
	{
		cout<<"Nhap phut:\n";
		cin>>tg.Phut;
		if(tg.Phut < 0 || tg.Phut > 59)
			cout<<"So phut khong hop le. Nhap lai";
	}while(tg.Phut < 0 || tg.Phut > 59);
}
void XuatTHOIGIAN(const THOIGIAN tg)
{
	if(tg.Gio >= 12)
	cout<<tg.Gio<<":"<<tg.Phut<<" PM";
	else 
		cout<<tg.Gio<<":"<<tg.Phut<<" AM";
}
struct NGAY 
{
	unsigned short Ngay, Thang, Nam;
};
void NhapNGAY(NGAY& ng)
{
	do 
	{
		cout<<"Nhap Ngay, Thang, Nam:\n";
		cin>>ng.Ngay>>ng.Thang>>ng.Nam;
		if(ng.Ngay < 0 || ng.Ngay > 31 || ng.Thang < 0 || ng.Thang > 12 || ng.Nam < 1600 || ng.Nam > 2015)
			cout<<"Du lieu khong hop le. Nhap lai!\n";
	}while(ng.Ngay < 0 || ng.Ngay > 31 || ng.Thang < 0 || ng.Thang > 12 || ng.Nam < 1600 || ng.Nam > 2015);
}
void XuatNGAY(const NGAY ng)
{
	cout<<ng.Ngay<<"/"<<ng.Thang<<"/"<<ng.Nam;
}
struct VE 
{
	string Tenphim;
	unsigned int Giatien;
	THOIGIAN Xuatchieu;        // Struct lồng trong struct
	NGAY Ngayxem;             // Struct lồng trong struct
};

void NhapVE(VE& v)
{
	fflush(stdin);
	cout<<"Nhap ten phim:\n";
	getline(cin, v.Tenphim);
	do 
	{
		cout<<"Nhap gia ve:\n";
		cin>>v.Giatien;
		if(v.Giatien < 0)
			cout<<"Gia tien phai >= 0!";
	}while(v.Giatien < 0);
	NhapTHOIGIAN(v.Xuatchieu);
	NhapNGAY(v.Ngayxem);
}
void XuatVE(const VE v)
{
	cout<<"Ten phim: "<<v.Tenphim<<endl;
	cout<<"Gia ve: "<<v.Giatien<<endl;
	cout<<"Xuat chieu: ";
	XuatTHOIGIAN(v.Xuatchieu);
	cout<<endl;
	cout<<"Ngay xem: ";
	cout<<endl;
	XuatNGAY(v.Ngayxem);
}

struct QUANLYVE 
{
	vector<VE> List;        // 1 vector List với element có kiểu là VE
};
void NhapDanhSach(vector<VE>& List)
{
	VE v;
	NhapVE(v);
	List.push_back(v);
}
void XuatDanhSach(const vector<VE> List)
{
	for(int i = 0; i < List.size(); i++)
	{
		XuatVE(List[i]);
		cout<<endl;
	}
}
void BienHoaDauTu(string& s)
{
	if(s[0] >= 'a' && s[0] <= 'z')
		s[0] -= 32;
	for(int i = 1; i < s.length() - 1 ; i++)
	{
		// Viết gì trong này?
		if(s[i] == ' ')
		{
			if(s[i + 1] >= 'a' && s[i + 1] <= 'z')
			{
				s[i + 1] -= 32;
			}
		}
	}
}
void BienTenPhim(vector<VE>& List)
{
	for(int i = 0; i < List.size(); i++)
	{
		BienHoaDauTu(List[i].Tenphim);
	}
}
unsigned int TinhTongGiaTien(const vector<VE> List)
{
	unsigned int Tong = 0;
	for(int i = 0; i < List.size(); i++)
	{
		Tong += List[i].Giatien;
	}
	return Tong;
}
void InterchangeSort(vector<VE>& List)
{
	for(int i = 0; i < List.size() - 1; i++)
	{
		for(int j = i + 1; j < List.size(); j++)
		{
			if(List[i].Giatien > List[j].Giatien)
			{
				swap(List[i], List[j]);
			}
		}
	}
}
int main()
{
	int chon;
	QUANLYVE QLV;
	system("color 1f");
	do 
	{
		system("cls");
		cout<<"0. Thoat\n\n";
		cout<<"1. Nhap Danh Sach\n\n";
		cout<<"2. Xuat Danh Sach\n\n";
		cout<<"3. Bien Hoa Dau Tu Ten Phim\n\n";
		cout<<"4. Xem Tong Gia Tien Tat Ca Ve\n\n";
		cout<<"5. Sap Xep Tang Dan Theo Gia Ve\n\n";
		cout<<"Chon menu:\n";
		cin>>chon;
		switch (chon)
		{
		case 0: break;
		case 1:
			{
				NhapDanhSach(QLV.List);
				break;
			}
		case 2:
			{
				XuatDanhSach(QLV.List);
				system("pause");
				break;
			}
		case 3:
			{
				BienTenPhim(QLV.List);
				XuatDanhSach(QLV.List);
				system("pause");
				break;
			}
		case 4:
			{
				unsigned int TongTien = TinhTongGiaTien(QLV.List);
				cout<<"Tong tien ve la "<<TongTien<<" VND";
				system("pause");
				break;
			}
		case 5:
			{
				InterchangeSort(QLV.List);
				XuatDanhSach(QLV.List);
				system("pause");
				break;
			}
		default:
			break;
		}
	}while(chon != 0);
	return 0;
}
