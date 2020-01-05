// Bài này a viết bằng C++. Ai đang viết bằng C thì tập chuyển qua C++ dần nhé ^^
#include <iostream>
#include <cmath>       // Thư viện toán học của C++
using namespace std;

int Bai1(int n)
{
	int tong = 0;
	for(int i = 1; i <= n; i++)
	{
		tong += i;
	}
	return tong;
}
int Bai2(int n)
{
	int tong = 0;
	for(int i = 1; i <= n; i++)
	{
		tong += pow(i, 2);          // Thư viện cmath của C++ thì tụi em ko cần ép kiểu sang số thực lun đó nhé. :)
	}
	return tong;
}

float Bai3(int n)
{
	float tong = 0;
	for(int i = 1; i <= n; i++)
	{
		tong += 1.0 / i;
	}
	return tong;
}

int Bai4(int n)
{
	int giaithua = 1;
	for(int i = 2; i <= n; i++)
	{
		giaithua = giaithua * i;
	}
	return giaithua;
}
int Bai5(int n)
{
	int tonggiaithua = 0;
	for(int i = 1; i <= n; i++)
	{
		tonggiaithua += Bai4(i);       // Tận dụng hàm Bai4
	}
	return tonggiaithua;
}

void main()
{
	int n;
	{
		cout<<"Nhap so nguyen duong n:\n";
		cin>>n;
		if(n < 0)
			cout<<"Du lieu yeu cau phai la so nguyen duong. Nhap lai!\n";
	}while(n < 0);
	cout<<"S1 = "<<Bai1(n)<<endl;        // Đặc biệt trong C++ chúng ta ko cần quan tâm đến đặc tả %. Rất tiện đó nhé. <<endl <=>\n
	cout<<"S2 = "<<Bai2(n)<<endl;
	cout<<"S3 = "<<Bai3(n)<<endl;
	cout<<"S4 = "<<Bai4(n)<<endl;
	cout<<"S5 = "<<Bai5(n)<<endl;
	system("pause");        // Hàm dừng màn hình trong C++
}