#include <iostream>
using namespace std;

//a + i <=> &a[0 + i] ;

//*(a+i) <=> a[i]
void NhapMang(int* a, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout<<"Nhap a["<<i<<"]:\n";
		//cin>>a[i];
		// Cách 2
		cin>>*(a+i);
		//cin>>*(i+a);
		//cin>>i[a];
	}
}

void XuatMang(int* a, int n)
{
	for(int i = 0; i < n; i++)
	{
		//cout<<a[i];
		//cout<<i[a];
		cout<<*(a+i)<<" ";
	}
}

void PhepCongConTro(int* a, int n)
{
	int* p = NULL;	 
	p = a;//  p = &a[0];
	p++;  // <=> p = &a[1];
	p += 3; // <=> p = &a[4];

	cout<<endl<<*p;

}
void PhepTruConTro(int* a, int n)
{
	int* p = NULL;	 
	p = &a[n - 1] ;
	p--; // <=> p = &a[n - 2];
	cout<<endl<<*p;
}

void XoaPhanTu(int*& a, int& n, int vitrixoa)
{
	for(int i = vitrixoa; i < n - 1; i++)
	{
		a[i] = a[i+1];
	}
	//n--;
	// 5 phan tu kieu int <=> 20 bytes 
	// Hàm realloc là resize (reset size) lại bộ nhớ đã xin cấp
	a = (int*)realloc(a, (--n) * sizeof(int));
}

void ThemPhanTu(int*& a, int& n, int phantuthem, int vitrithem)
{
	n++;
	a = (int*)realloc(a, n * sizeof(int));
	for(int i = n - 1; i > vitrithem; i--)
	{
		a[i] = a[i-1];
	}
	a[vitrithem] = phantuthem;
}
// Thêm số 0 vào sau các phần tử là số đặc biệt. Số đặc biệt là số có tổng chữ số lẻ = tổng chữ số chẵn
// VD: 2837 la so dac biet

// Xóa tất cả các phần tử xuất hiện 2 lần trong mảng. 

//199.	(**) Hãy viết chương trình phát sinh ngẫu nhiên mảng các số nguyên gồm 10.000 phần tử,
// mỗi phần tử có giá trị từ 0 đến 32.000 và xây dựng chương trình con thống kê số lần xuất hiện các phần tử trong mảng, 
//sau đó cho biết phần tử nào xuất hiện nhiều lần nhất.
//Ví dụ: Mảng:	5 6 11 4 4 5 4
//5 xuat hien 2 lan
//6 xuat hien 1 lan
//11 xuat hien 1 lan
//4 xuat hien 3 lan
//Ket luan: 4 xuat hien nhieu lan nhat

//200.	Cho mảng A có n phần tử. Nhập vào số nguyên k (k 0), dịch phải xoay vòng mảng A k lần.
//Ví dụ:	Mảng A:	5 7 2 3 1 9
//Nhập k=2
//Dịch phải xoay vòng mảng A:	1 9 5 7 2 3


int main()
{
	int* a = NULL;
	int n = 0;
	int chon;
	do 
	{
		system("cls");
		cout<<"0. Thoat\n\n";
		cout<<"1. Nhap Mang\n\n";
		cout<<"2. Xuat Mang\n\n";
		cout<<"3. Xoa Phan Tu\n\n";
		cout<<"4. Them Phan Tu\n\n";
		cout<<"Moi ban chon menu:";
		cin>>chon;
		switch (chon)
		{
		case 0: break;
		case 1:
			{
				do 
				{
					cout<<"Nhap so luong phan tu:\n";
					cin>>n;
					if(n < 0)
						cout<<"So luong la phai >= 0!\n";
				}while(n < 0);
				a = new int[n];	// Xin cấp phát n ô nhớ kiểu int ở vùng nhớ HEAP
				NhapMang(a, n);break;
			}
		case 2: XuatMang(a, n); PhepTruConTro(a,n); system("pause"); break;
		case 3: 
			{
				int vitrixoa;
				do 
				{
					cout<<"Nhap vi tri muon xoa:\n";
					cin>>vitrixoa;
					if(vitrixoa < 0 || vitrixoa >= n)
						cout<<"Vi tri khong ton tai. Nhap lai\n";
				}while(vitrixoa < 0 || vitrixoa >= n);
				XoaPhanTu(a, n, vitrixoa);
				break;
			}
		case 4:
			{
				int phantuthem, vitrithem;
				cout<<"Nhap phan tu can them:";
				cin>>phantuthem;
				do 
				{
					cout<<endl<<"Ban muon them vao vi tri nao:";
					cin>>vitrithem;
					if(vitrithem < 0 || vitrithem > n)
						cout<<"Vi tri khong ton tai. Nhap lai\n";
				}while(vitrithem < 0 || vitrithem > n);
				ThemPhanTu(a,n, phantuthem, vitrithem);
				break;
			}
		default:
			break;
		}
	}while(chon != 0);

	if(a != NULL)
	{
		delete[] a;	// Thu hồi n ô nhớ vừa xin cấp phát trước đó 
	}
	return 0;
}