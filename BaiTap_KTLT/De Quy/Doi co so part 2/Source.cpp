#include <iostream>
using namespace std;

void DoiCoSo(int n, int heso)
{
	if(n == 0)
		return;
	else 
	{
		DoiCoSo(n / heso, heso);		
		cout<<n % heso;
	}
}

void DoiThapPhanSangHexa(int n)
{
	if(n == 0)
		return;
	else 
	{
		DoiThapPhanSangHexa(n / 16);		
		int chuso = n % 16;
		if(chuso == 10)
			cout<<"A";
		else if(chuso == 11)
			cout<<"B";
		else if(chuso == 12)
			cout<<"C";
		else if(chuso == 13)
			cout<<"D";
		else if(chuso == 14)
			cout<<"E";
		else if(chuso == 15)
			cout<<"F";
		else 
			cout<<chuso;
	}
}
int main()
{
	int n = 1012;
	//DoiCoSo(n, 8);      // Chuyển sang hệ bát phân
	DoiThapPhanSangHexa(n);
	system("pause");
	return 0;
}