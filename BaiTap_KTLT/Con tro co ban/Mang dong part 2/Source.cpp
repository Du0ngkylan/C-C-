#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
void TaoMangNgauNhien(int* a, int n)
{
	srand(time(0));
	for(int i = 0; i < n; i++)
	{
		a[i] = rand()% 20;
	}
}
void NhapMang(int* a, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("Nhap a[%d]:\n",i);
		scanf_s("%d",a);
		a++;
	}
}

void XuatMang(int* a, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d\t",*a);
		a++;
	}
}
int TimMinLe(int* a, int n)
{
	int min = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] % 2 != 0)
		{
			min = a[i];
			break;
		}
	}
	if(min == 0)
		return min;
	for(int i = 0; i < n; i++)
	{
		if(a[i] < min && a[i] % 2 != 0)
		{
			min = a[i];
		}
	}
	return min;
}
void HoanVi(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
void SapXepGiamDan(int* a, int n)
{
	for(int i = 0; i < n - 1; i++)
  {
      for(int j = i + 1; j < n; j++)
      {
            if(a[i] < a[j])
           {
              HoanVi(&a[i], &a[j]);
           }
      }
  }
}
int Bai1(int* a, int n)
{
	int minle = TimMinLe(a, n);
	if(minle == 0)
	{
		return -1;
	}
	int temp[20];
	int ntemp = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] % 2 == 0)
		{
			temp[ntemp] = a[i];
			ntemp++;
		}
	}
	SapXepGiamDan(temp, ntemp);
	for(int i = 0; i < ntemp; i++)
	{
		if(temp[i] < minle)
			return temp[i];
	}
	return -1;
}

void Bai2(int* a, int n)
{
	for(int i = 0; i < n; i++)
  {
      for(int j = 0; j < n; j++)
      {
            if(a[i] < a[j])
           {
              printf("(%d, %d)\n",a[i],a[j]);
           }
      }
  }
}
// Hàm huyền thoại 
bool KiemTraTrung(int* a, int n, int index)
{
	for(int i = 0; i < index; i++)
	{
		if(a[i] == a[index])
			return true;         // Bị trùng số đằng trước
	}
	return false;
}

int DemSoLanXuatHienCuax(int* a, int n, int x)
{
	int dem = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] == x)
			dem++;
	}
	return dem;
}

void LietKeTanXuat(int* a, int n)
{
	SapXepGiamDan(a, n);
	printf("\n");
	XuatMang(a, n);
	for(int i = 0; i < n; i++)
	{
		if(KiemTraTrung(a, n, i))
			continue;
		else 
		{
			int dem = DemSoLanXuatHienCuax(a, n, a[i]);
			printf("%d xuat hien %d lan\n",a[i],dem);
		}
	}
}

bool KiemTraMangDoiXung(int* a, int n)
{
	for(int i = 0; i < n / 2; i++)
	{
		if(a[i] != a[n - 1 - i])
			return false;
	}
	return true;
}
void main()
{
	system("color 1f");
	int n = 5;
	int* a = NULL;
	a = new int[n];
	//TaoMangNgauNhien(a,n);
	NhapMang(a,n);
	XuatMang(a,n);

	//int MaxChanNhoHonMoiLe = Bai1(a, n);
	//if(MaxChanNhoHonMoiLe == -1)
	//{
	//	printf("\nKo co phan tu thoa yeu cau!");
	//}
	//else 
	//	printf("\nKet qua la %d",MaxChanNhoHonMoiLe);
	//Bai2(a, n);
	printf("\n");
	//LietKeTanXuat(a,n);
	if(KiemTraMangDoiXung(a,n))
		printf("Mang doi xung\n\n");
	else 
		printf("Mang khong doi xung\n\n");
	if(a != NULL)
		delete []a;
	_getch();
}