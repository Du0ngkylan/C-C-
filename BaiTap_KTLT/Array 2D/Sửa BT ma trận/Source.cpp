#include <iostream>      // input output stream. Dòng nhập xuất chuẩn C++
using namespace std;

void NhapMaTran(int a[][10], int sodong, int socot)
{
	for(int i = 0; i < sodong * socot; i++)
	{
		cout<<"Nhap a["<<i/socot<<"]["<<i % socot<<"]:\n";
		cin>>a[i / socot][i % socot];
	}
}
void XuatMaTran(int a[][10], int sodong, int socot)
{
	for(int i = 0; i < sodong * socot; i++)
	{
		cout<<a[i / socot][i % socot];
		if((i + 1) % socot == 0)
			cout<<endl;
	}
}
bool ktsoam(int a[][10],int sodong,int socot)         // HÀM BÀI 1
{
	for(int i = 0; i < sodong; i++)
	{
		for(int j = 0; j < socot; j++)
		{
			if(a[i][j] < 0)
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
bool KiemTraDongChuaNT(int a[][10], int sodong, int socot, int vitridong)
{
	for(int j = 0; j < socot; j++)
	{
		if(KiemTraNT(a[vitridong][j]))         // Phát hiện có 1 số NT trên dòng thì return true luôn
			return true;
	}

	return false;
}
int TongDong(int a[][10], int sodong, int socot, int vitridong)
{
	int tong = 0;
	for(int j = 0; j < socot; j++)
	{
		tong += a[vitridong][j];	
	}
	return tong;
}
int TongDongChuaNT(int a[][10],int sodong,int socot)         // HÀM BÀI 2
{
	int tong = 0;
	for(int i = 0; i < sodong; i++)
	{
			if(KiemTraDongChuaNT(a, sodong, socot, i))          // Phát hiện dòng i chứa số NT
			{
				tong += TongDong(a, sodong,socot, i);          // cộng dồn tổng dòng vào biến tổng
			}
	}
	return tong;
}
void HoanViDong(int a[][10],int sodong,int socot, int h1, int h2)
{
    int j,tam;
    for(j = 0;j < socot;j++)
    {
		swap(a[h1][j], a[h2][j]);
    }
}
void SapTangDan(int a[][10],int sodong,int socot)         // Interchange sort
{
	for(int i = 0; i < sodong * socot - 1; i++)
	{
		for(int j = i + 1; j < sodong * socot; j++)
		{
			if(a[i / socot][i % socot] > a[j % socot][j / socot])
				swap(a[i / socot][i % socot], a[j / socot][j % socot]);
		}
	}
}

void SapTangDan(int a[], int n)
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}
void SapGiamDan(int a[], int n)
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(a[i] < a[j])
				swap(a[i], a[j]);
		}
	}
}
void SapXepDongChanTangDongLeGiam(int a[][10],int sodong,int socot)
{
	for(int i = 0; i < sodong; i++)
	{
		if(i % 2 == 0)
			SapTangDan(a[i], socot);
		else 
			SapGiamDan(a[i], socot);
	}
	
}
bool KiemTraChuSoThu2Chan(int x)
{
	if(x < 10)
		return false;
	while(x > 99)     // Tức là x có 3 chữ số trở lên
	{
		x /= 10;
	}
	// Ra vòng lặp thì x còn 2 chữ số
	if((x % 10) % 2 == 0)
		return true;
	return false;
}
int DemPtuCoChuSoThu2Chan(int a[][10],int sodong,int socot)
{
	int dem = 0;
	for(int i = 0; i < sodong * socot; i++)
	{
		if(KiemTraChuSoThu2Chan(a[i / socot][i % socot])) 
			dem++;
	}
	return dem;
}
void main()
{
	int a[10][10];
    int sodong = 0, socot = 0;
	int chon;
	do 
	{
		system("cls");
		cout<<"0. Thoat\n\n";
		cout<<"1. Nhap ma tran\n\n";
		cout<<"2. Xuat Ma Tran\n\n";
		cout<<"3. Kiem tra so am\n\n";
		cout<<"4. Tong cac dong chua so nguyen to\n\n";
		cout<<"5. Hoan vi hai dong\n\n";
		cout<<"6. Sap xep mang tang tu trai qua phai, tu tren xuong duoi\n\n";
		cout<<"7. Sap xep dong chan tang dan, dong le giam dan\n\n";
		cout<<"8. Dem so luong so co chu so thu 2 la chan\n\n";
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
						if(sodong < 0 || socot < 0 || sodong > 10 || socot > 10)
							cout<<"Du lieu khong hop le. Nhap lai!\n";
					}
					while(sodong < 0 || socot < 0 || sodong > 10 || socot > 10); 	
					NhapMaTran(a, sodong, socot);
				    break;
				}
			case 2:
				{
					 XuatMaTran(a, sodong, socot);
					 system("pause");
				}break;
			case 3:
				{
					if(ktsoam(a, sodong, socot))
						cout<<"Ma tran chua so am";
					else 
						cout<<"Ma tran khong chua so am";
					system("pause");
				} break;
			case 4:
				{
					int Tong = TongDongChuaNT(a, sodong, socot);

				}break;
			case 5:
				{

				}break;
			case 6:
				{
					
				}break;
			case 7:
				{
					
				}break;
		} 
	}while(chon != 0);
}