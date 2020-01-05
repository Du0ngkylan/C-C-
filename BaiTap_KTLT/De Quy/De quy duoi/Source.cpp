#include <iostream>
#include <ctime>
using namespace std;

int TinhGiaiThua(int n)
{
	if(n == 1)
		return 1;
	else 
		return n * TinhGiaiThua(n - 1);
}

int TinhGiaiThua2(int n, int giaithua = 1)
{
	if(n == 1)
		return giaithua;
	else 
		return TinhGiaiThua2(n - 1, giaithua * n); 
}

int TinhTongS1(int n)
{
	if(n == 1)
		return 1;
	else 
		return n + TinhTongS1(n - 1); 
}
int TinhTongS2(int n, int tong = 0)
{
	if(n == 0)
		return tong;
	else 
		return TinhTongS2(n - 1, tong + n); 
}

int main()
{
	clock_t start = clock();
	int n = 500;
	cout<<TinhTongS1(n);
	clock_t finish = clock();
	double s =( double)(finish - start) / 1000.0;
	cout<<endl<<s<<endl;

	//start = clock();
	///*cout<<TinhTongS2(n)<<endl;*/
	//finish = clock();
	//s = (finish - start) / 1000.0;
	//cout<<endl<<s;
	system("pause");
	return 0;
}