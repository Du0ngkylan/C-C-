#include "Header.h"
int main()
{
	vector<PHONG> List;
	int chon;
	system("color a");
	do 
	{
		system("cls");
		cout<<"0.Thoat\n\n";
		cout<<"1.Them Phong\n\n";
		cout<<"2.Xuat Danh Sach Phong\n\n";
		cout<<"3.Liet Ke Cac Phong Trong Trong Danh Sach\n\n";
		cout<<"4.Tinh Tong So Luong Giuong\n\n";
		cout<<"5.Xoa Khoi Danh Sach Nhung Phong ban\n\n";
		cout<<"Moi ban chon menu:\n";
		cin>>chon;
		switch (chon)
		{
		case 0: break;
		case 1: NhapDanhSach(List); break;
		case 2: XuatKhachSan(List); system("pause"); break;
		case 3: XuatCacPhongTrong(List); system("pause"); break;
		case 4:{ int Tong = TongGiuong(List);cout<<"Tong so luong giuong la "<<Tong; system("pause"); break;}
		case 5: XoaPhongDangBan(List); XuatKhachSan(List); cin.get(); break;
		default:
			break;
		}
	}
	while(chon != 0);
	return 0;
}