//Bai 24: Viet chuong trinh nhap so nguyen duong n.
//	Kiem tra n co phai la so nguyen to hay khong?

//=============================================================


#include <iostream>
using namespace std;

bool isPrime(int n)
{
	if(n < 2) return false;
	for(int i = 2; i*i <= n; i++)
		if(n % i == 0) return false;
	return true;
}

int main()
{
	unsigned int n;
	cout<<"Nhap vao so nguyen duong n: ";
	cin>>n;
	if(isPrime(n))
		cout<< n << " la so nguyen to!";
	else
		cout<< n <<" khong la so nguyen to!";
	cout<<endl;
}