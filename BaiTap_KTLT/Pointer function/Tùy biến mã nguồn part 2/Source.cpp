#include <iostream>
#include <cmath>
using namespace std;
// 1. Tính tổng các số nguyên tố
// 2. Tính tổng các số chính phương
// 3. Tính tổng các số đặc biệt. Số đặc biệt là số có tổng chữ số lẻ = tổng chữ số chẵn
// 4. Xóa các số nguyên tố
// 5  Xóa các số chính phương


// 6. Sắp xếp các phần tử:
 // A/Chẵn trước, 0 giữa, lẻ cuối.
 // B/Lẻ  trước, 0 giữa, chẵn cuối
//  C/ 0 trước, Chắn giữa, lẻ cuối.
// VD: 5 1 2 8 0 4 0 7
// A: 2 8 4 0 0 5 1 7
// B: 5 1 7 0 0 2 8 4
// C: 0 0 2 8 4 5 1 7 


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
				if(x % i == 0)
					return false;
			}
		}
	}
	return true;
}

bool KiemTraChinhPhuong(int x)
{
	int canbac2  = sqrt(x);
	return (canbac2 * canbac2) == x;     // Cách ghi nhanh
}

bool KiemTraSoDacBiet(int x)
{
	int temp = x;
	int tongchusochan = 0;
	int tongchusole = 0;
	while(temp != 0)
	{
		int chuso = temp % 10;
		if(temp % 2 == 0)
		tongchusochan += chuso;
		else 
			tongchusole += chuso;
		temp /= 10;
	}
	if(tongchusochan == tongchusole)
		return true;
	return false;
}

int TinhTongTuyChon(int* a, int n, bool (*KiemTra)(int))
{
	int tong = 0;
	for(int i = 0; i < n; i++)
	{
		if(KiemTra(a[i]) == true)
			tong += a[i];
	}
	return tong;
}
int main()
{
	int n = 0;
	int* a = NULL;
	int chon;
	do 
	{
		system("cls");
		cout<<"1. Nhap Mang\n\n";
		cout<<"2. Xuat Mang\n\n";
		cout<<"3. Tong Cac So Nguyen To\n\n";
		cout<<"4. Tong Cac So Chinh Phuong\n\n";
		cout<<"5. Tong Cac So Dac Biet\n\n";
		cout<<"6. Xoa Cac So Nguyen To\n\n";
		cout<<"7. Xoa Cac So Chinh Phuong\n\n";
		cout<<"Moi ban chon menu:\n";
		cin>>chon;
		switch (chon)
		{
		case 0:
			break;
		case 1:
			{
				do 
				{
					cout<<"Nhap so luong phan tu:\n";
					cin>>n;
					if(n <  0)
						cout<<"So luong khong hop le. Nhap lai!\n";
				}while(n < 0);
				a = new int[n];
				NhapMang(a, n);
				break;
			}
		case 2:
			{
				XuatMang(a, n); system("pause"); break;
			}
		case 3:
			{
				int TongNguyenTo = TinhTongTuyChon(a, n, KiemTraNT);
				cout<<TongNguyenTo<<endl;
				system("pause");
				break;
			}
		case 4:
			{
				int TongChinhPhuong  = TinhTongTuyChon(a, n, KiemTraChinhPhuong);
				cout<<TongChinhPhuong<<endl;
				system("pause");
				break;
			}

		case 5:
			{
				int TongDacBiet = TinhTongTuyChon(a, n, KiemTraSoDacBiet);
				cout<<TongDacBiet<<endl;
				system("pause");
				break;
			}
		default:
			break;
		}
	}
	while(chon != 0);
	if(a != NULL)
		delete []a;
	return 0;
}