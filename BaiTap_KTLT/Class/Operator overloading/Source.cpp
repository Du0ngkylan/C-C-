#include <iostream>
using namespace std;

class SOPHUC 
{
private:
	float a, b;
public:
	SOPHUC()
	{
		a = 1;
		b = 0;
	}
	SOPHUC(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	friend istream&  operator>>(istream& is, SOPHUC& x)
	{
		cout<<"Nhap phan thuc:\n";
		is>>x.a;
		cout<<"Nhap phan ao:\n";
		is>>x.b;
		return is;
	}
	friend ostream&  operator<<(ostream& os, SOPHUC x)
	{
		if(x.a == 0)
			os<<x.b<<endl;
		else if(x.b == 0)
			os<<x.a<<endl;
		else if(x.b < 0)
			os<<x.a<<" "<<x.b<<"i"<<endl;
		else 
			os<<x.a<<" + "<<x.b<<"i"<<endl;
		return os;
	}
	SOPHUC operator+(SOPHUC y);
	SOPHUC operator-(SOPHUC y);
	SOPHUC operator*(SOPHUC y);
	SOPHUC operator/(SOPHUC y);
};
SOPHUC SOPHUC::operator+(SOPHUC y)
{
	SOPHUC tong;
	tong.a = this->a + y.a;
	tong.b = this->b + y.b;
	return tong;
}
SOPHUC SOPHUC::operator-(SOPHUC y)
{
	SOPHUC hieu;
	hieu.a = this->a - y.a;
	hieu.b = this->b - y.b;
	return hieu;
}
SOPHUC SOPHUC::operator*(SOPHUC y)
{
	SOPHUC tich;
	//a1 * b1 – a2 * b2, a1 * b2 + a2 * b1
	tich.a = this->a * y.a - this->b * y.b;
	tich.b = this->a * y.b +  y.a * this->b;
	return tich;
}
SOPHUC SOPHUC::operator/(SOPHUC y)
{
//	Thuong.thuc = (z1.thuc * z2.thuc + z1.ao * z2.ao)/((z2.thuc)^2 + (z2.ao)^2);
//Thuong.ao = (z1.ao * z2.thuc - z1.thuc * z2.ao)/((z2.thuc)^2 + (z2.ao)^2);
	SOPHUC thuong;
	thuong.a =( this->a * y.a + this->b * y.b)/(y.a * y.a + y.b * y.b);
	thuong.b =(this->b * y.a - this->a * y.b) /(y.a * y.a + y.b * y.b);
	return thuong;
}
void main()
{
	SOPHUC x,y;
	cin>>x>>y;
	cout<<x + y;
	cout<<x-y;
	cout<<x*y;
	cout<<x / y;
	system("pause");
}