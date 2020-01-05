#pragma once
#include <iostream>
#include <string>
using namespace std;
class SINHVIEN
{
	friend class LIST;
	string ID, HoTen;
	float DiemTB;
public:
	float GetDiemTB()
	{
		return this->DiemTB;
	}
	void Nhap();
	void Xuat();
	SINHVIEN(void);
	~SINHVIEN(void);
};

