#include <iostream>
using namespace std;

// Hàm tính giai thừa sử dụng đệ quy tuyến tính
int TinhGiaiThua(int n)
{
	// ĐK Dừng
	if(n == 1)
		return 1;
	
	return n * TinhGiaiThua(n - 1);
}

// Tính tổng S(n) = 1 + 2 + ... + n
int TinhTongSn(int n)
{
	if(n == 1)
		return 1;
	else 
		return n + TinhTongSn(n - 1);
}
// Hàm tính tổng giai thừa .VD n = 5 thì S = 1! + 2! + 3! + 4! + 5!

int TinhTongGiaiThua(int n)
{
	// ĐK Dừng
	if(n == 1)
		return 1;
	else 
	{
		return TinhGiaiThua(n) + TinhTongGiaiThua(n - 1);
	}
}
// Hàm tính tổng S(n) = 1/1 + 1/2 + 1/3 + ... + 1/n
float TinhTong3(int n)
{
	//ĐK Dừng
	if(n == 1)
		return 1;
	else 
	{
		return 1.0 / n + TinhTong3(n - 1);
	}
}
//  1      +     1     + ... + 1
//1 x 2        2 x 3           n * (n + 1)
float TinhTong4(int n)
{
	// ĐK Dừng
	if(n == 1)
		return 0.5;
	else 
		return 1.0 / (n * (n + 1)) + TinhTong4(n - 1);
}

// S(n) = can(2 + can(2 + can(2 + ... + can2)))))  có n dấu căn
float TinhTong5(int n)
{
	if(n == 1)
	{
		return sqrt(2);
	}
	else 
	{
		return sqrt(2 + TinhTong5(n - 1)); 
	}
}

// Đếm số lượng chữ số của 1 số
int DemChuSo(unsigned int n)
{
	if(n == 0)
		return 0;
	else 
		return 1 + DemChuSo(n / 10);
}

int ChuSoMax = -1, ChuSoMin = 10;

void TimChuSoMaxMin(int n)
{
	if(n == 0)
		return;
	int chuso = n % 10;
	if(chuso > ChuSoMax)
		ChuSoMax = chuso;
	if(chuso < ChuSoMin)
		ChuSoMin = chuso;

	TimChuSoMaxMin(n / 10);
}

bool KiemTraSoToanChuSoChan(unsigned int n)
{
	if(n == 0)
		return true;

	if((n % 10) % 2 != 0)
		return false;

	return  KiemTraSoToanChuSoChan(n / 10);
}
int main()
{
	unsigned int n = 248624;

	TimChuSoMaxMin(n);

	cout<<"Chu so Max = "<<ChuSoMax<<endl;
	cout<<"Chu so Min = "<<ChuSoMin<<endl;
	if(KiemTraSoToanChuSoChan(n) == true)
		cout<<"So "<<n<<" toan chu so chan";
	else 
		cout<<"So "<<n<<" chua chu so le!";

	system("pause");
	return 0;
}