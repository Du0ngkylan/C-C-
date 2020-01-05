#include "SINHVIEN.h"

void SINHVIEN::Nhap()
{
	fflush(stdin);
	cout<<"Nhap ID:\n";
	getline(cin, ID);
	cout<<"Nhap Ho ten:\n";
	getline(cin, HoTen);
	do 
	{
		cout<<"Nhap vao diem TB:\n";
		cin>>this->DiemTB;
		if(DiemTB < 0 || DiemTB > 10)
			cout<<"Diem trung binh khong hop le!. Nhap lai\n";
	}while(DiemTB < 0 || DiemTB > 10);
}

void SINHVIEN::Xuat()
{
	cout<<endl<<"ID : "<<this->ID<<endl;
	cout<<"Ho ten : "<<this->HoTen<<endl;
	cout<<"Diem TB : "<<this->DiemTB<<endl;
}

SINHVIEN::SINHVIEN(void)
{
}


SINHVIEN::~SINHVIEN(void)
{
}
