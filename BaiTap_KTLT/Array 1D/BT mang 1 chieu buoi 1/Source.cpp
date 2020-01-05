#include <iostream>
#include <cmath>    // Thư viện toán học của C++
using namespace std;

void NhapMang(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout<<"Nhap vao a["<<i<<"]:\n";
		cin>>a[i];
	}
}

void XuatMang(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout<<a[i]<<"\t";
	}
}

int TimKiemPhanTu(int a[], int n, int phantucantim)
{
	for(int i = 0; i < n; i++)
	{
		if(a[i] == phantucantim)
			return i;
	}

	return -1;
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
bool KiemTraMangToanNguyenTo(int a[], int n)
{
	// Ta nên kiểm tra 1 điều kiện ngược lại để có thể nhanh chóng kết luận
	for(int i = 0; i < n; i++)
	{
		if(KiemTraNT(a[i]) == false) // Nếu phát hiện 1 phần tử bất kỳ không phải số nguyên tố
			return false;
	}

	return true;        // Mảng toàn số NT
}
int main()
{
	system("color 1f");
	int a[50];
	int n = 0;    // Số lượng phần tử
	int chon;
	do 
	{
		system("cls");
		cout<<"0. Thoat\n\n";
		cout<<"1. Nhap Mang\n\n";
		cout<<"2. Xuat Mang\n\n";
		cout<<"3. Tim Kiem Phan Tu\n\n";
		cout<<"4. Kiem Tra Mang Co Phai Toan Nguyen To\n\n";
		cout<<"Moi ban chon menu:\n";
		cin>>chon;
		switch (chon)
		{
		case 0: break;
		case 1:
			{
				do 
				{
					cout<<"Nhap vao so luong phan tu:\n";
					cin>>n;
					if(n < 0 || n > 50)
						cout<<"So luong khong hop le. Nhap lai!\n";
				}while(n < 0 || n > 50);
				NhapMang(a, n);
				break;
			}
		case 2:
			{
				XuatMang(a, n);
				system("pause");
				break;
			}
		case 3:
			{
				int x;
				cout<<"Nhap phan tu can tim:\n";
				cin>>x;
				if(TimKiemPhanTu(a, n, x) == -1)   // Ko tìm thấy
					cout<<"Ko tim thay "<<x;
				else 
					cout<<"Tim thay "<<x<<" tai chi so "<<TimKiemPhanTu(a, n, x);
				system("pause");
				break;
			}
		case 4:
			{
				if(KiemTraMangToanNguyenTo(a, n) == true)
					cout<<"Mang toan so NT\n";
				else 
					cout<<"Mang khong phai toan so NT\n\n";
				system("pause");
				break;
			}
		default:cout<<"Ban chon menu bi sai. Hoa mat ha? ^^"; system("pause"); 
			break;
		}
	}while(chon != 0);
}