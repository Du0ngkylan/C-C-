#include <iostream>
using namespace std;

struct POINT 
{
	float x, y;
};

void NhapDiem(POINT& p)
{
	cout<<"Nhap hoanh do, tung do:\n";
	cin>>p.x>>p.y;
}

void XuatDiem(const POINT p)
{
	cout<<"("<<p.x<<","<<p.y<<")";
}