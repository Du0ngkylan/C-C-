//1/Viết CT thực hiện những yêu cầu sau:
//a. Nhập mảng 1 chiều các vé xem phim(VE). Biết rằng 1 vé xem phim gồm các thành phần sau:
//-Tên phim: chuỗi string
//-Gía tiền: số nguyên kiểu unsigned int
//-Xuất chiếu: kiểu Thời gian (THOIGIAN)
//-Ngày xem: kiểu dữ liệu ngày (NGAY)
//b. Xuất mảng
//c.Tính tổng giá tiền của tất cả các vé trong mảng
//d.Sắp xếp mảng tăng dần theo giá tiền



#include <iostream>
#include <string>
using namespace std;

class THOIGIAN
{
private:
  short Gio, Phut;
public:
	short GetGio() const;
	void SetGio(short);
	short GetPhut() const;
	void SetPhut(short);
	void Nhap();
	void Xuat();
	THOIGIAN()
	{
		Gio = 12;
		Phut = 0;
	}
	THOIGIAN(short g, short p)
	{
		this->Gio = g;
		this->Phut = p;
	}
};

short THOIGIAN::GetGio() const 
{
	return this->Gio;
}
void THOIGIAN::SetGio(short newgio )
{
	this->Gio = newgio;
}
short THOIGIAN::GetPhut() const 
{
	return this->Phut;
}
void THOIGIAN::SetPhut(short newphut )
{
	this->Phut = newphut;
}
void THOIGIAN::Nhap()
{
	cout<<"Nhap Gio, phut:\n";
	cin>>Gio>>Phut;
}

void THOIGIAN::Xuat()
{
	cout<<endl<<Gio<<":"<<Phut<<endl;
}
class NGAY
{
	friend class VE;
private:
	short ngay, thang, nam;
public:
	void Nhap();
	void Xuat();
	NGAY()
	{
		ngay = 1;
		thang = 1;
		nam = 1990;
	}

};

void NGAY::Nhap()
{
	cout<<"Nhap ngay, thang, nam:\n";
	cin>>ngay>>thang>>nam;
}
void NGAY::Xuat()
{
	cout<<endl<<ngay<<"/"<<thang<<"/"<<nam<<endl;
}

class VE
{
private:
	string TenPhim;
	unsigned int Gia;
	THOIGIAN Xuatchieu;
	NGAY Ngayxem;
public:
	unsigned int GetGia() const;
	void SetGia(unsigned int);
	void Nhap();
	void Xuat();
	VE()
	{
		TenPhim = "Chua co";
		Gia = 0;
		Xuatchieu.SetGio(0);
		Ngayxem.ngay = 1;
		Ngayxem.thang = 1;
		Ngayxem.nam = 1990;
	}
};
unsigned int VE::GetGia()  const
{
	return this->Gia;
}
void VE::SetGia(unsigned int newgia)
{
	this->Gia = newgia;
}
void VE::Nhap()
{
	cout<<"Nhap Ten phim:\n";
	fflush(stdin);
	getline(cin, this->TenPhim);
	do 
	{
		cout<<"Nhap gia ve:\n";
		cin>>this->Gia;
		if(this->Gia < 0)
			cout<<"Gia ve khong hop le. Nhap lai!\n";
	}while(this-> Gia < 0);
	Xuatchieu.Nhap();
	Ngayxem.Nhap();
}

void VE::Xuat()
{
	cout<<endl<<"Ten Phim: "<<this->TenPhim<<endl;
	cout<<"Gia ve: "<<this->Gia<<endl;
	Xuatchieu.Xuat();
	Ngayxem.Xuat();
}

int LonHon(const void* x, const void* y)
{
	if(((VE*)x)->GetGia() > ((VE*)y)->GetGia())
		return 1;
	else  if(((VE*)x)->GetGia() == ((VE*)y)->GetGia())
		return 0;
	else 
		return -1;
}
int NhoHon(const void* x, const void* y)
{
	if(((VE*)x)->GetGia() < ((VE*)y)->GetGia())
		return 1;
	else  if(((VE*)x)->GetGia() == ((VE*)y)->GetGia())
		return 0;
	else 
		return -1;
}
void main()
{
	VE *list;
	int n;
	do 
	{
		cout<<"Nhap so luong ve:\n";
		cin>>n;
		if(n < 0)
			cout<<"So luong khong hop le. Nhap lai!\n";
	}while(n < 0);
	list = new VE[n];
	unsigned int tong = 0;
	for(int i = 0; i < n; i++)
	{
		list[i].Nhap();
		tong += list[i].GetGia();
	}
	qsort((void*)list,n, sizeof(VE), LonHon);
	cout<<endl<<"Tong gia ve = "<<tong;
	for(int i = 0; i < n; i++)
	{
		list[i].Xuat();
		
	}

	system("pause");
   //c.Tính tổng giá tiền của tất cả các vé trong mảng
   //d.Sắp xếp mảng tăng dần theo giá tiền


	delete []list;
}


