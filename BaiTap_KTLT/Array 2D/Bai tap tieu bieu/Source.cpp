#include <iostream>
#include <ctime>
using namespace std;

void TaoNgauNhien(int a[][10], int sodong, int socot)
{
	srand(time(0));
	for(int i = 0; i < sodong; i++)
	{
		for(int j = 0; j < socot; j++)
		{
			a[i][j] = rand()%50 + 1;
		}
	}
}
void NhapMang2Chieu(int a[][10], int sodong, int socot)
{
	for(int i = 0; i < sodong; i++)
	{
		for(int j = 0; j < socot; j++)
		{
			cout<<"Nhap vao a["<<i<<"]["<<j<<"]:\n";
			cin>>a[i][j];
		}
	}
}
void XuatMang2Chieu(int a[][10], int sodong, int socot)
{
	for(int i = 0; i < sodong; i++)
	{
		for(int j = 0; j < socot; j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
}
bool TimPhanTu(int a[][10], int sodong, int socot, int phantucantim)
{
	for(int i = 0; i < sodong; i++)
	{
		for(int j = 0; j < socot; j++)
		{
			if(a[i][j] == phantucantim)
				return true;
		}
	}
	return false;
}
bool KiemTraNT(int x)
{
	if(x < 2)
	{
		return false;
	}
	if(x > 2)
	{
		if(x % 2 == 0)
			return false;
		else 
		{
			for(int i = 3; i <= (int) sqrt(x); i += 2)
			{
				if(x % 2 == 0)
					return false;
			}
		}
	}
	return true;
}
bool KiemTraMangToanNT(int a[][10], int m, int n)
{
	int i, j, dem = 0;
	for (i = 0; i < m; i++)
	{	
			for (j = 0; j < n; j++)
				if (KiemTraNT(a[i][j]) == false)
					return false;
	}
          return true;
} 
int TinhTongDong(int a[][10], int sodong, int socot, int chisodong)
{
	int tong = 0;
	for(int j = 0;j < socot; j++)
	{
		tong += a[chisodong][j];
	}
	return tong;
}
int TinhTongDuongCheoChinh(int a[][10], int sodong, int socot)
{
	int tong = 0;
	for(int i = 0; i < sodong; i++)
	{
		tong += a[i][i];
	}
	return tong;
}
int TinhTongDuongCheoPhu(int a[][10], int sodong, int socot)
{
	int tong = 0;
	for(int i = 0, j = socot - 1; i < sodong; i++, j--)
	{
		tong += a[i][j];
	}
	return tong;
}
//1 2 3 4 
//4 5 6 5 
//7 8 9 6
//1 2 3 0
int TongTrenDCChinh(int a[][10], int n)
{
	int i, j, tong;
	tong = 0;
	for (i = 0; i < n; i++)
	{
			for (j = 0; j< n; j++)
				if (i < j)
					tong = tong + a[i][j];
	}
    return tong;
}
int TimMax(int a[][10], int sodong, int socot)
{
	int max = a[0][0];
	for(int i = 0; i < sodong; i++)
	{
		for(int j = 0; j < socot; j++)
		{
			if(a[i][j] > max)
				max = a[i][j];
		}
	}
	return max;
}
void main()
{
	int a[10][10];
	int sodong  = 0, socot = 0;
	int chon;
	system("color 1f");
	do 
	{
		system("cls");
		cout<<"0. Thoat\n\n";
		cout<<"1. Tao Ngau Nhien\n\n";
		cout<<"2. Nhap Ma Tran\n\n";
		cout<<"3. Xuat Ma Tran\n\n";
		cout<<"Moi ban chon menu:\n";
		cin>>chon;
		switch (chon)
		{
		case 0: break;
		case 1:
			{
				do 
				{
					cout<<"Nhap so dong, so cot:\n";
					cin>>sodong>>socot;
					if(sodong < 0 || sodong > 10 || socot < 0 || socot > 10)
						cout<<"Du lieu khong hop le. Nhap lai!\n";
				}while(sodong < 0 || sodong > 10 || socot < 0 || socot > 10);
				TaoNgauNhien(a, sodong, socot);
				break;
			}
		case 2:
			{
				do 
				{
					cout<<"Nhap so dong, so cot:\n";
					cin>>sodong>>socot;
					if(sodong < 0 || sodong > 10 || socot < 0 || socot > 10)
						cout<<"Du lieu khong hop le. Nhap lai!\n";
				}while(sodong < 0 || sodong > 10 || socot < 0 || socot > 10);
				NhapMang2Chieu(a, sodong, socot);
				break;
			}
		case 3:
			{
				XuatMang2Chieu(a, sodong, socot);
				system("pause");
				break;
			}
		default:
			break;
		}
	}while(chon != 0);
	system("pause");
}