#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct PHONG
{
	string  MAPHONG;
	string TENPHONG;
	unsigned int DONGIAPHONG;
	unsigned int SOGIUONG;
	bool TINHTRANGPHONG;
};
void NhapPhong(PHONG& p)
{
	cout << "Nhap ma phong:" << endl;
	do
	{
		cout << "Nhap ma phong (toi da 5 ky tu): " << endl;
		getline(cin, p.MAPHONG);
		if (p.MAPHONG.size() > 5)
			cout << "Ma phong qua 5 ky tu, xin nhap lai." << endl;
	} while (p.MAPHONG.size() > 5);
	
	cout << "Nhap ten phong:" << endl;
	do
	{
		cout << "Nhap ten phong (toi da 30 ky tu): " << endl;
		getline(cin, p.TENPHONG);
		if (p.TENPHONG.size() > 30)
			cout << "Ten phong qua 30 ky tu, xin nhap lai." << endl;
	} while (p.TENPHONG.size() > 30);
	cout << "Nhap don gia thue: ";
	cin >> p.DONGIAPHONG;
	cout << "Nhap so luong giuong: ";
	cin >> p.SOGIUONG;
	do 
	{
	   cout << "Nhap tinh trang phong (0 trong, 1 ban): ";
	   cin >> p.TINHTRANGPHONG;
	   if(p.TINHTRANGPHONG != 0 && p.TINHTRANGPHONG != 1)
	   {
		   cout<<"Nhap 0 hoac 1 de the hien tinh trang phong ban nhe.!\n";
	   }
	}while(p.TINHTRANGPHONG != 0 && p.TINHTRANGPHONG != 1);
}
void XuatPhong(const PHONG p)
{
	cout << "Ma phong: " << p.MAPHONG << endl;
	cout << "Ten phong: " << p.TENPHONG << endl;
	cout << "Don gia phong: " << p.DONGIAPHONG << endl;
	cout << "So luong giuong: " << p.SOGIUONG << endl;
	if (p.TINHTRANGPHONG == 1)
		cout << "Tinh trang phong: ban" << endl;
	else
		cout << "Tinh trang phong: trong" << endl;
}
void NhapDanhSach(vector<PHONG>& a)
{
	PHONG p;
	fflush(stdin);
	NhapPhong(p);
	a.push_back(p);
}
void XuatKhachSan(const vector<PHONG> a)
{
	for (int i = 0; i < a.size(); i++)
	{
		cout << "Thong tin phong thu: " << i + 1;
		XuatPhong(a[i]);
		cout << endl;
	}
}
void XuatCacPhongTrong(const vector<PHONG> a)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i].TINHTRANGPHONG == 0)
		{
			XuatPhong(a[i]);
			cout << endl;
		}
	}
}
int TongGiuong(const vector<PHONG> a)
{
	int SoGiuong = 0;
	for (int i = 0; i < a.size(); i++)
	{
		SoGiuong += a[i].SOGIUONG;
	}
	return SoGiuong;
}

void XoaPhongDangBan(vector<PHONG>& a)
{
	for(int i = 0; i < a.size(); i++)
	{
		if(a[i].TINHTRANGPHONG == 1)
		{
			a.erase(a.begin() + i);
			i--;
		}
	}
}