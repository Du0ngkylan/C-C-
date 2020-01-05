#include <iostream>
using namespace std;

void NhapMaTran(int a[][10], int sodong, int socot)
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
void XuatMaTran(int a[][10], int sodong, int socot)
{
	for(int i = 0; i < sodong; i++)
	{
		for(int j = 0; j < socot; j++)
		{
			cout<<a[i][j]<<"\t";
		}
		// Để ra được hình dáng của 1 ma trận
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
				return true;               // Hàm kết thúc và trả về true             
		}
	}
	return false;        // Ko tìm thấy
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
	int i, j;
	for (i = 0; i < m; i++)
	{	
			for (j = 0; j < n; j++)
				if (KiemTraNT(a[i][j]) == false)    // Phát hiện a[i][j] ko phải số NT
					return false;                  
	}
    return true;          // Mảng toàn số NT
} 
int TinhTongDong(int a[][10], int sodong, int socot, int vitridongcantinh)
{
	int tongdong = 0;
	for(int j = 0; j < socot; j++)
	{
		tongdong += a[vitridongcantinh][j];
	}
	return tongdong;
}
// Bổ sung TinhTongCot

int TinhTongPToDuongCheoChinh(int a[][10], int sodong, int socot)
{
	int tong = 0;
	for(int i = 0; i < sodong; i++)
	{
		tong = tong + a[i][i];
	}
	return tong;
}
int TinhTongNuaTrenDuongCheoChinh(int a[][10], int sodong, int socot)
{
	int tong = 0;
	for(int i = 0; i < sodong - 1; i++)
	{
		for(int j = i + 1; j < socot; j++)
		  tong = tong + a[i][i];
	}
	return tong;
}
//  1 2 3
//  4 5 6
//  7 8 9

// tong = a[0][1] + a[0][2] + a[1][2]

//  Tính tổng nữa dưới đường chéo chính
// tong = a[1][0] + a[2][0] + a[2][1]

//Tìm giá trị nhỏ nhất/lớn nhất của mảng
void main()
{
	int a[10][10]; // Khai báo mảng 2 chiều a gồm tối đa 10 dòng,10 cột
	int sodong = 0, socot = 0;
	int chon;
	do
	{
		system("cls");
		cout<<"0. Thoat\n\n";
		cout<<"1. Nhap Mang\n\n";
		cout<<"2. Xuat Mang\n\n";
		// Bổ sung thêm menu cho đủ
		cout<<"3. Tinh Tong Phan Tu O Duong Cheo Chinh\n\n";
		cout<<"Moi ban chon menu:\n";
		cin>>chon;
		switch (chon)
		{
		case 0:break;
		case 1:
			{
				do 
				{
					cout<<"Nhap so dong, so cot:\n";
					cin>>sodong>>socot;
					if(sodong < 0 || sodong > 10 || socot < 0 || socot > 10)
						cout<<"Du lieu khong hop le. Nhap lai!\n";
				}while(sodong < 0 || sodong > 10 || socot < 0 || socot > 10);
				NhapMaTran(a, sodong, socot);
				break;
			}
		case 2:
			{
				XuatMaTran(a, sodong, socot);
				system("pause");
				break;
			}
		case 3:
			{
				if(sodong != socot)       // Chứng tỏ ko phải ma trận vuông
					cout<<"Menu nay chi ap dung cho ma tran vuong!\n";
				else 
				{
					int tong = TinhTongPToDuongCheoChinh(a, sodong, socot);
					cout<<"Tong = "<<tong;
				}
				system("pause");
				break;
			}
		default:
			break;
		}
	}while(chon != 0);

	// Làm menu đàng hoàng nhé
	/*int b[3][3] = 
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};*/
}