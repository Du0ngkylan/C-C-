#pragma once
#include "POINT.h"

struct STRANGLE
{
	POINT A, B, C;
};

void NhapCacDinh(STRANGLE& ST)
{
	cout<<"Nhap Dinh A:\n";
	NhapDiem(ST.A);
	cout<<"Nhap Dinh B:\n";
	NhapDiem(ST.B);
	cout<<"Nhap Dinh C:\n";
	NhapDiem(ST.C);
}

void XuatCacDinh(const STRANGLE ST)
{
	cout<<"Dinh A: ";
	XuatDiem(ST.A);
	cout<<"  ";
	cout<<"Dinh B: ";
	XuatDiem(ST.B);
	cout<<"  ";
	cout<<"Dinh C: ";
	XuatDiem(ST.C);
	cout<<endl;
}

POINT TimTrongTam(const STRANGLE ST)
{
	POINT G;
	G.x  = (ST.A.x + ST.B.x + ST.C.x) / 3.0;
	G.y = (ST.A.y + ST.B.y + ST.C.y) / 3.0;

	return G;
}

float TinhDoDai2Diem(const POINT P1, const POINT P2)
{
	float DoDai = sqrt( pow(P2.x - P1.x, 2) + pow(P2.y - P1.y, 2));
	return DoDai;
}

float TinhChuVi(const STRANGLE ST)
{
	return TinhDoDai2Diem(ST.A, ST.B) + TinhDoDai2Diem(ST.B, ST.C) + TinhDoDai2Diem(ST.A, ST.C);
}

float TinhDienTich(const STRANGLE ST)
{
	float NuaChuVi = TinhChuVi(ST) / 2;
	float AB = TinhDoDai2Diem(ST.A, ST.B);
	float BC = TinhDoDai2Diem(ST.B, ST.C);
	float AC = TinhDoDai2Diem(ST.A, ST.C);
	float S= sqrt(NuaChuVi * (NuaChuVi  - AB) * (NuaChuVi - AC) * (NuaChuVi - BC));
	return S;
}

void XuatDinhGanToaDoNhat(const STRANGLE ST)
{
	POINT O;
	O.x = 0;
	O.y = 0;
	float OA = TinhDoDai2Diem(ST.A, O);
	float OB = TinhDoDai2Diem(ST.B, O);
	float OC = TinhDoDai2Diem(ST.C, O);

	float min = OA;
	OB < min ? min = OB : min = min;
	OC < min ? min = OC : min = min;

	cout<<"Cac Dinh Gan Goc Toa Do Nhat La: ";
	if(OA == min)
		cout<<"A ";
	if(OB == min)
		cout<<"B ";
	if(OC == min)
		cout<<"C ";
}
