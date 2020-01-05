//#include <iostream>
//#include <cmath>
//using namespace std;
//
//
//struct PHANSO
//{
//	int tu;
//	int mau;
//};
//
//istream& operator>>(istream& is,PHANSO& ps)             // Nạp chồng toán tử >>. Trả về is là đối tượng của class istream. Nhớ phải trả về kiểu tham chiếu
//{
//	cout<<"Nhap tu so:\n";
//	is>>ps.tu;
//	do 
//	{
//		cout<<"Nhap mau so:\n";
//		is>>ps.mau;
//		if(ps.mau == 0)
//			cout<<"Mau so phai khac 0. Nhap lai!\n";
//	}while(ps.mau == 0);
//	return is;
//}
//
//ostream& operator<<(ostream& os,const PHANSO ps) // Nạp chồng toán tử <<. Trả về os là đối tượng của class ostream. Nhớ phải trả về kiểu tham chiếu
//{
//	os<<ps.tu<<"/"<<ps.mau;
//	return os;
//}
//
//int TimUCLN(int a, int b)           // Hàm tìm UCLN 
//{
//	a = abs(a);
//	b = abs(b);
//	while(a != b)
//	{
//		if(a > b)
//			a = a - b;
//		else 
//			b = b - a;
//	}
//	return a;
//}
//void RutGon(PHANSO& ps)
//{
//	int UCLN = TimUCLN(ps.tu , ps.mau);
//	ps.tu /= UCLN;
//	ps.mau /= UCLN;
//}
//
//PHANSO operator+(const PHANSO x, const PHANSO y)
//{
//	PHANSO Tong;
//	Tong.tu = x.tu * y.mau + x.mau * y.tu;
//    Tong.mau = x.mau * y.mau;
//	int UCLN = TimUCLN(Tong.tu, Tong.mau);
//	Tong.tu /= UCLN;
//	Tong.mau /= UCLN;
//	return Tong;
//}
//int TimBCNN(int x, int y)
//{
//	int max;
//	int BCNN;
//	if(x > y)
//	{
//			BCNN = x;
//			max = x;
//	}
//	else 
//	{
//		BCNN = y;
//		max = y;
//	}
//	while(BCNN % x != 0 || BCNN % y != 0)
//	{
//		BCNN += max;
//	}
//	return BCNN;
//}
//// 3 , 4
//// BCNN = 4, max = 4
//// BCNN = 4 + 4 = 8
//// BCNN = 8 + max = 12
//// 
//int main()
//{
//	PHANSO a, b;
//	cout<<"Nhap phan so a:\n";
//	cin>>a;
//	cout<<"Nhap phan so b:\n";
//	cin>>b;
//
//	cout<<"Phan so a: ";
//	cout<<a<<endl;
//	cout<<"Phan so b: ";
//	cout<<b<<endl;
//	PHANSO Tong = a + b;          // Dùng toán tử  + như với các kiểu DL cơ sở vì đã nạp chồng toán tử +
//
//	cout<<a<<" + "<<b<<" = "<<Tong;
//	system("pause");
//	return 0;
//}
//
