#include <iostream>
#include <cmath>   

using namespace std;

void NhapMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap vao a[" << i << "]:\n";
		cin >> a[i];
	}
}

void XuatMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
}

int Timmin(int a[], int n)
{
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
	}
	return min;
}
int Timduongmin(int a[], int n)		// 15
{
	for (int i = 0; i < n; i++)
	{
		if (Timmin(a, n) == a[i] && a[i] > 0)
			return i;
	}
}
int Timmax(int a[], int n)			
{
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return max;
}
int TimViTriDuongMax(int a[], int n)   // 16
{
	int max = Timmax(a, n);
	for(int i = 0; i < n; i++)
	{
		if(a[i] > 0)
		{
			if(a[i] == max)
				return i;
		}
	}
}
bool KiemTraNT(int x)
{
	if (x < 2)
	{
		return false;
	}
	if (x > 2)
	{
		if (x % 2 == 0)
			return false;
		else
		{
			for (int i = 3; i <= (int)sqrt(x); i += 2)
			{
				if (x % i == 0)
					return false;
			}
		}
	}
	return true;
}
void InVitriphantuNT(int a[], int n)		//17
{
	for (int i = 0; i < n; i++)
	{
		if (KiemTraNT(a[i]) == true)
			cout << i << "\t";
	}
}
int Timvitrixcuoicung(int a[], int n, int x)		//18
{
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] == x)
			return i;
	}
	return -1;     // Ko tìm thấy x trong mảng
}
// 1 3 5 2 3 8 
// x = 3
// trả về: 4
void InVitriNTLonhon23(int a[], int n)		//19
{
	for (int i = 0; i < n; i++)
	{
		if (KiemTraNT(a[i]) == true && a[i] > 23)
			cout << i << "\t";
	}
}
void InPhanTuLaboi3va5(int a[], int n)		//20
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 3 == 0 && a[i] % 5 == 0)
			cout << a[i] << "\t";
	}
}
bool KiemTraHoanThien(int x)
{
	// Số hoàn thiện là số có tổng các ước số < nó  bằng chính nó.
	//VD: 6 là số hoàn thiện vì 1 + 2 + 3 = 6

	int tong = 0;
	for(int i = 1; i < x; i++)
	{
		if(x % i == 0)
		{
			tong = tong + i;
			if(tong > x )
				return false;
		}
	}
	if(tong == x)          
		return true;          // x là số hoàn thiện
	else 
		return false;
}
int TimSoHoanThienMinCuoiCung(int a[], int n)		//21
{
	int Hoanthienmin = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		if(KiemTraHoanThien(a[i]))
		{
			if(Hoanthienmin == 0)           // Lúc này chứng tỏ hoanthienmin vẫn chưa thay giá trị
			{
				Hoanthienmin = a[i];
			}
			else 
			{
				if(a[i] < Hoanthienmin)
					Hoanthienmin = a[i];
			}
		}
	}
	return Hoanthienmin;
}
int Timchannhonhat(int a[], int n)		//22
{
	int Chanmin = 0;
	for (int i = 0; i < n; i++)
	{
		if(a[i] % 2 == 0)
		{
			if(Chanmin == 0)
			{
				Chanmin = a[i];
			}
			else 
			{
				if(a[i] < Chanmin)
					Chanmin = a[i];
			}
		}
	}
	return Chanmin;
}
// 5 2 3 1 8
// Trả về : 2
int TimPhanTuAmLonNhat(int a[], int n)		//23
{
	int amlonnhat = -1;
	for (int i = 0; i < n; i++)
	{
		if(a[i] < 0)
		{
			if(amlonnhat == -1)
			{
				amlonnhat = a[i];
			}
			else 
			{
				if(a[i] > amlonnhat)
					amlonnhat = a[i];
			}
		}
	}
	return amlonnhat;
}
void InPhanTuxaxnhat(int a[], int n, int x)		//24
{
	int khoangcachmax = abs(a[0] - x);
	int phantuxaxnhat = a[0];
	for (int i = 1; i < n; i++)
	{
		int khoangcach = abs(a[i] - x);
		if(khoangcach > khoangcachmax)
		{
			khoangcachmax = khoangcach;
			phantuxaxnhat = a[i];
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(abs(a[i] - x) == khoangcachmax)
			cout<<a[i]<<"\t";
	}
}
void TimViTriPhanTuganxnhat(int a[], int n, int x)		//25
{
	int khoangcachmin = abs(a[0] - x);
	int phantuganxnhat = a[0];
	for (int i = 1; i < n; i++)
	{
		int khoangcach = abs(a[i] - x);
		if(khoangcach < khoangcachmin)
		{
			khoangcachmin = khoangcach;
			phantuganxnhat = a[i];
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(abs(a[i] - x) == khoangcachmin)
			cout<<i<<"\t";
	}
}
void timdoanab(int a[], int n)		//26
{
	int A = Timmin(a, n);
	int B = Timmax(a, n);
	cout << "[" << A << ";" << B << "]" << endl;
}
int TimPhanTuDauTienLonHon2010(int a[], int n)		//27
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 2010)
		{
			return a[i];
		}
	}
	return 0;
}
int timXY(int a[], int n, int X, int Y)			//28
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] > X && a[i] < Y) // Tức nó nằm trong đoạn X, Y
		{
			return a[i];
		}
	}
	return X;     // Ko có thì trả về X
}
bool KiemTraChinhPhuong(int x)
{
	int canbac2  = sqrt(x);
	return (canbac2 * canbac2) == x;     // Cách ghi nhanh
}
int TimChinhPhuongDauTien(int a[], int n)		//29
{
	for(int i = 0; i < n; i++)
	{
		if(KiemTraChinhPhuong(a[i]))
		{
			return a[i];
		}
	}
	return 0;
}
int TimViTriPhanTuDauCoTichLanCanBangChinhNo(int a[], int n)		//30
{
	for (int i = 1; i < n - 1; i++)
	{
		int tich = a[i - 1] * a[i + 1];
		if (a[i] == tich)
		{
			return i;
		}
	}
	return 0;
}
int main()
{
	system("color 1f");
	int a[50];
	int b[50];
	int n = 0;    // Số lượng phần tử
	int chon;
	do
	{
		system("cls");
		cout << "0. Thoat\n\n";
		cout << "1. Nhap Mang\t\t\t\t";
		cout << "2. Xuat Mang\n\n";
		cout << "15. Tim vi tri phan tu duong be nhat\t";
		cout << "16. Tim vi tri cua phan tu lon nhat\n\n";
		cout << "17. Tim vi tri cac phan tu nguyen to\t";
		cout << "18. Tim vt phan tu == x  cuoi cung \n\n";
		cout << "19. Vi tri phan tu nguyen to < 23\t";
		cout << "20. Cac phan tu la boi cua 3 va 5\n\n";
		cout << "21. Tim so hoan thien nho nhat\t\t";
		cout << "22. Tim gia tri chan nho nhat trong mang\n\n";
		cout << "23. Gia tri am lon nhat trong mang\t";
		cout << "24. Nhung phan tu co gia tri xa x nhat\n\n";
		cout << "25. Nhung vi tri co gia tri gan x nhat\t";
		cout << "26. Tim doan [a;b] chua tat ca cac gt \n\n";
		cout << "27. Tim  gt dau tien lon hon 2010\t";
		cout << "28. Tim  gt dau tien trong khoang (X;Y)\n\n";
		cout << "29. Tim chinh phuong dau tien\t\t";
		cout << "30. Tim vt dau tien = tich 2 pt lan can\n\n";
		cout << "Moi ban chon menu:\n";
		cin >> chon;
		switch (chon)
		{
		case 0: break;
		case 1:
		{
				  do
				  {
					  cout << "Nhap vao so luong phan tu:\n";
					  cin >> n;
					  if (n < 0 || n > 50)
						  cout << "So luong khong hop le. Nhap lai!\n";
				  } while (n < 0 || n > 50);
				  NhapMang(a, n);
				  break;
		}
		case 2:
		{
				  XuatMang(a, n);
				  system("pause");
				  break;
		}
		case 15:
		{
			cout<<Timduongmin(a, n);
				   system("pause");
				   break;
		}
		case 16:
		{
			       cout<<TimViTriDuongMax(a, n);
				   system("pause");
				   break;
		}
		case 17:
		{
			       InVitriphantuNT(a, n);
				   system("pause");
				   break;
		}
		case 18:
		{
				   int x;
				   cout << "Nhap x: ";
				   cin >> x;
				   cout<<Timvitrixcuoicung(a, n, x);
				   system("pause");
				   break;
		}
		case 19:
		{
				   InVitriNTLonhon23(a, n);
				   system("pause");
				   break;
		}
		case 20:
		{
			       InPhanTuLaboi3va5(a, n);
				   system("pause");
				   break;
		}
		case 21:
		{
			int sohoanthienmin = TimSoHoanThienMinCuoiCung(a, n);
			cout<<"So hoan thien nho nhat cuoi cung trong mang la "<<sohoanthienmin;
				   system("pause");
				   break;
		}
		case 22:
		{
			cout<<"Phan tu chan nho nhat trong mang la "<<Timchannhonhat(a, n);
				system("pause");
				break;
		}
		case 23:
		{
				int ammax = TimPhanTuAmLonNhat(a, n);
				cout<<"Phan tu am max = "<<ammax;
				system("pause");
				break;
		}
		case 24:
		{
				int x;
				cout << "Nhap x: ";
				cin >> x;
				InPhanTuxaxnhat(a, n, x);
				system("pause");
				break;
		}
		case 25:
		{
				int x;
				cout << "Nhap x: ";
				cin >> x;
				TimViTriPhanTuganxnhat(a, n, x);
				system("pause");
				break;
		}
		case 26:
		{
				timdoanab(a, n);
				system("pause");
				break;
		}
		case 27:
		{
			cout<<TimPhanTuDauTienLonHon2010(a, n);
				system("pause");
				break;
		}
		case 28:
		{
				int X, Y;
				cout << "Nhap khoang (X;Y): ";
				cin >> X >> Y;
				cout<<timXY(a, n, X, Y);
				system("pause");
				break;
		}
		case 29:
		{
			cout<<"Phan tu chinh phuong dau tien la "<<TimChinhPhuongDauTien(a, n);
				system("pause");
				break;
		}
		case 30:
		{
			cout<<TimViTriPhanTuDauCoTichLanCanBangChinhNo(a, n);
				system("pause");
				break;
		}
		default:cout << "Ban chon menu bi sai. Hoa mat ha? ^^"; system("pause");
			break;
		}
	} while (chon != 0);
}