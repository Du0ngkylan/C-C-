#include "VECTOR.h"
#include "VECTOR.cpp"
class SOPHUC 
{
public:
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
			os<<x.b;
		else if(x.b == 0)
			os<<x.a;
		else if(x.b < 0)
			os<<x.a<<" "<<x.b<<"i";
		else 
			os<<x.a<<" + "<<x.b<<"i";
		return os;
	}
	SOPHUC operator+(SOPHUC y);
	SOPHUC operator-(SOPHUC y);
	SOPHUC operator*(SOPHUC y);
	SOPHUC operator/(SOPHUC y);
};
void main()
{
	VECTOR<char> list;
	/*SOPHUC x;
	for(int i = 0; i < 10 ;i++)
	{
		x.a = i;
		x.b = i + 1;
	    list.push_back(x);
	}*/

	for(char c = 'A' ; c <= 'z' ; c++)
	{
	list.push_back(c);
	}
	for(int i = 0; i < list.size(); i++)
		cout<<list.at(i)<<"\t";

	list.clear();

	system("pause");
}