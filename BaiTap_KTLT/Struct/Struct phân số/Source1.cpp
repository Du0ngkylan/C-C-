#include <iostream>
using namespace std;


struct PHANSO
{
	int tu;
	int mau;
};

void NhapPhanSo(PHANSO& ps)
{
	cout<<"Nhap tu so:\n";
	cin>>ps.tu;
	do 
	{
		cout<<"Nhap mau so:\n";
		cin>>ps.mau;
		if(ps.mau == 0)
			cout<<"Mau so phai khac 0!\n";
	}while(ps.mau == 0);
}

void XuatPhanSo(const PHANSO ps)
{
	cout<<ps.tu<<"/"<<ps.mau<<endl;
}

int TimUCLN(int a, int b)
{
	a = abs(a);
	b = abs(b);
	   while(a != b)
	   {
		   if(a > b)
			   a = a - b;
		   else 
			   b = b - a;
	   }
	   return a;
}
void RutGon(PHANSO& ps)
{
	int UCLN = TimUCLN(ps.tu, ps.mau);
	ps.tu /= UCLN;
	ps.mau /= UCLN;
}
PHANSO TinhTongPhanSo(const PHANSO x,const PHANSO y)
{
	PHANSO Tong;
	Tong.tu = x.tu * y.mau + x.mau * y.tu;
    Tong.mau = x.mau * y.mau;
	RutGon(Tong);
	return Tong;
}
PHANSO TinhHieuPhanSo(const PHANSO x,const PHANSO y)
{
	PHANSO Hieu;
	Hieu.tu = x.tu * y.mau - x.mau * y.tu;
	Hieu.mau = x.mau * y.mau;
	RutGon(Hieu);
	return Hieu;
}
PHANSO TinhTichPhanSo(const PHANSO x,const PHANSO y)
{
	PHANSO Tich;
	Tich.tu = x.tu * y.tu;
	Tich.mau = x.mau * y.mau;
	RutGon(Tich);
	return Tich;
}
PHANSO TinhThuongPhanSo(const PHANSO x, const PHANSO y)
{
	PHANSO Thuong;
	Thuong.tu = x.tu * y.mau;
	Thuong.mau = x.mau * y.tu;
	RutGon(Thuong);
	return Thuong;
}
bool KiemTraPhanSoToiGian(const PHANSO ps)
{
	int UCLN = TimUCLN(ps.tu, ps.mau);
	return UCLN == 1; 
}
int TimBCNN(int a, int b)
{
	int max = a > b ? a : b;
	int BCNN = max;

	while(BCNN % a != 0 || BCNN % b != 0)
	{
		BCNN += max;
	}
	return BCNN;
}
void QuyDong2PhanSo(PHANSO& x, PHANSO& y)
{
	int BCNN = TimBCNN(x.mau, y.mau);

	x.tu = x.tu * (BCNN / (float)x.mau);
	y.tu = y.tu * (BCNN / (float)y.mau);
	x.mau = BCNN;
	y.mau = BCNN;
}
bool KiemTraDuong(const PHANSO ps)
{
	return (float)ps.tu / ps.mau > 0;
}

int SoSanh2PhanSo(const PHANSO ps1, const PHANSO ps2)
{
	if((float)ps1.tu / ps1.mau > (float)ps2.tu / ps2.mau)
		return 1;
	else if((float)ps1.tu / ps1.mau == (float)ps2.tu / ps2.mau)
		return 0;
	else 
		return -1;
}
int main()
{
	PHANSO x, y;
	NhapPhanSo(x);
	XuatPhanSo(x);
	if(KiemTraPhanSoToiGian(x))
	{
		cout<<"Phan so x toi gian\n";
	}
	else 
		cout<<"Phan so x khong toi gian\n";
	if(KiemTraDuong(x))
	{
		cout<<"Phan so x la phan so duong\n";
	}
	else 
		cout<<"Phan so x la phan so am\n";
	NhapPhanSo(y);
	XuatPhanSo(y);

	QuyDong2PhanSo(x, y);
	cout<<"2 Phan so sau khi quy dong:\n";
	XuatPhanSo(x);
	XuatPhanSo(y);

	if(SoSanh2PhanSo(x, y) == 1)
		cout<<"x > y\n";
	else if(SoSanh2PhanSo(x, y) == 0)
		cout<<"x == y\n";
	else 
		cout<<"x < y\n";

	PHANSO Tong = TinhTongPhanSo(x, y);
	PHANSO Hieu = TinhHieuPhanSo(x, y);
	PHANSO Tich = TinhTichPhanSo(x, y);
	PHANSO Thuong = TinhThuongPhanSo(x, y);

	cout<<"Tong = "; 
	XuatPhanSo(Tong);
	cout<<"Hieu = "; 
	XuatPhanSo(Hieu);
	cout<<"Tich = "; 
	XuatPhanSo(Tich);
	cout<<"Thuong = "; 
	XuatPhanSo(Thuong);
	system("pause");
	return 0;
}
