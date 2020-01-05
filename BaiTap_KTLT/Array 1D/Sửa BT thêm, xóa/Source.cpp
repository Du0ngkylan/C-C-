#include <iostream>
#include <ctime>            
using namespace std;

void TaoNgauNhien(int a[], int n)
{
	srand(time(0));                // second random 
	//1. Nếu muốn random 1 số bất kỳ thì chỉ việc để a[i] = rand();
	//2. Nếu muốn random 1 số trong khoảng từ a đến b thì a[i] = rand()%b + a;
	for(int i = 0; i < n; i++)
	{
		a[i] = rand()%10 + 1;
	}
}
void NhapMang(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout<<"Nhap a["<<i<<"]:\n";
		cin>>a[i];
	}
}
void XuatMang(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d\t",i[a]);
	}
}
void XoaPhanTu(int a[],int& n, int vitrixoa)
{
	for(int i = vitrixoa; i < n; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
void ThemPhanTu(int a[],int& n, int vitrithem, int giatrithem)
{
	for(int i = n; i > vitrithem; i--)
	{
		a[i] = a[i - 1];
	}
	a[vitrithem] = giatrithem;
	n++;
}
void XoaPhanTuViTriLe(int a[],int& n)
{
	bool check = true;      // Mặc định cho là true
	for(int i = 0; i < n; i++)
	{
		if(i % 2 != 0 && check == true)
		{
			XoaPhanTu(a, n, i);
			check = false;
		}
		if(i % 2 == 0 && check == false)
		{
			XoaPhanTu(a, n, i);
			check = true;
		}
	}
}
int XoaPhanTux(int a[],int& n, int x)
{
	bool check = false;
	for(int i = 0; i < n; i++)
	{
		if(a[i] == x)        // Đã phát hiện ra có phần tử == x
		{
			check = true;
			XoaPhanTu(a, n, i);
		    i--;            // i-- để có thể xóa liên tiếp những phần tử == x kế nhau              
		}
	}
	if(check == false)
     return -1;
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
void XoaTatCaPhanTuMax(int a[], int& n)
{
	int max = Timmax(a, n);
	for (int i = 1; i < n; i++)
	{
		if(a[i] == max)
		{
			XoaPhanTu(a, n, i);
			i--;
		}
	}
}
int DemPhanTux(int a[], int n, int x)
{
	int dem = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] == x)
			dem++;
	}
	return dem;
}
void XoaPhanTuXHNhieuHon1lan(int a[], int& n)
{
	for(int i = 0; i < n; i++)
	{
		int dem = DemPhanTux(a, n, a[i]); // Đếm xem 1 phần tử a[i] xuất hiện bao nhiêu lần
		if(dem > 1)
		{
			XoaPhanTux(a, n , a[i]);
		}
	}
}
void XoaPhanTuGiuLai1(int a[], int& n)
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i  + 1; j < n; j++)      // Duyệt kiểm tra những đứa đứng sau xem có đứa nào trùng với
			                              // a[i] không?
		{
			if(a[j] == a[i])
			{
				XoaPhanTu(a, n, j);
				j--;
			}
		}
	}
}
/* DẠNG BÀI TẬP THÊM   */
// Thêm x vào sau tất cả các phần tử chẵn
void ThemXVaoSauAllSoChan(int a[],int &n,int x)
{
  for(int i = 0; i < n; i++)
 {
	 if(a[i] % 2==0)
    {
     ThemPhanTu(a,n,i+1,x);
     i++;
    }
 }
}

void main()
{
	int chon;
	do 
	{
		system("cls");
		cout<<"0.Thoat\n\n";
		cout<<"1. Nhap Mang\n\n";
		cout<<"2. Xuat Mang\n\n";
		// Tụi em tự bổ sung menu để test các hàm nhé
	}
	while(chon != 0);
}