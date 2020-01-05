//#include <iostream>
//#include <string>
//using namespace std;
//
//// Ở đây tôi xin giới thiệu phương pháp operator overloading (nạp chồng toán tử) để nạp chồng 2 toán tử >> , << ,[]
//// Các bạn có thể lên mạng tìm hiểu thật kỹ thêm để có thể nạp chồng những toán tử khác như + - * / [] () ,...
//struct THOIGIAN
//{
//   unsigned short Gio, Phut;       // Kiểu số nguyên nhỏ 2 bytes ko dấu tức là số nguyên dương
//};
//// Vì cin là đối tượng của class istream nên phương thức nạp chồng sau trả về kiểu istream. Và chú ý là phải trả về kiểu tham chiếu.
//
//istream& operator>>(istream& is,THOIGIAN& tg)
//{
//	do 
//    {
//	  cout<<"Nhap gio:\n";
//	  is>>tg.Gio;                  // Chú ý là is>>
//	  if(tg.Gio < 0 || tg.Gio > 24)
//		 cout<<"Gio khong hop le. Nhap lai\n";
//	}while(tg.Gio < 0 || tg.Gio > 24);
//	do 
//	{
//		cout<<"Nhap so phut:\n";
//		is>>tg.Phut;
//		if(tg.Phut < 0 || tg.Phut > 59)
//			cout<<"So phut khong hop le. Nhap lai\n";
//	}while(tg.Phut < 0 || tg.Phut > 59);
//	
//	return is;               // Trả về đối tượng is
//}
//
//// Vì cout là đối tượng của class ostream nên phương thức nạp chồng sau trả về kiểu ostream. Và chú ý là phải trả về kiểu tham chiếu.
//ostream& operator<<(ostream& os,THOIGIAN tg)
//{
//	os<<tg.Gio<<" gio : "<<tg.Phut<<" phut\n";
//	return os;                // Trả về đối tượng os
//}
//
//struct NGAY
//{
//    unsigned short Ngay, Thang, Nam;      // Kiểu số nguyên nhỏ 2 bytes ko dấu tức là số nguyên dương
//};
//
//istream& operator>>(istream& is,NGAY& ng)
//{
//	do 
//    {
//	  cout<<"Nhap ngay:\n";
//	  is>>ng.Ngay;                  
//	  if(ng.Ngay < 1 || ng.Ngay > 31 )                      // Gỉa thiết rằng ngay < 1 và ngay > 31 là không hợp lệ.
//		cout<<"Ngay khong hop le.Nhap lai!\n";
//	}while(ng.Ngay < 1 || ng.Ngay > 31) ;
//	do 
//	{
//		cout<<"Nhap thang:\n";
//		is>>ng.Thang;
//		if(ng.Thang < 1 || ng.Thang > 12)
//			cout<<"Thang khong hop le. Nhap lai\n";
//	}while(ng.Thang < 1 || ng.Thang > 12);
//	do 
//	{
//		cout<<"Nhap nam:\n";
//		is>>ng.Nam;
//		if(ng.Nam < 0)
//			cout<<"Nam khong hop le. Nhap lai\n";
//	}while(ng.Nam < 0);
//	return is;               // Trả về đối tượng is
//}
//ostream& operator<<(ostream& os, NGAY& ng)
//{
//	os<<ng.Ngay<<"/"<<ng.Thang<<"/"<<ng.Nam<<endl;
//	return os;
//}
//
//struct VE
//{
//	string tenPhim; 
//	unsigned int giaTien;        // Kiểu số nguyên ko dấu tức là số nguyên dương
//	THOIGIAN xuatChieu;        // xuatChieu kiểu THOIGIAN vừa định nghĩa
//	NGAY ngayXem;              // ngayXem kiểu NGAY vừa định nghĩa
//};
//
//istream& operator>>(istream& is, VE& v)
//{
//	fflush(stdin);
//	cout<<"Nhap ten phim:\n";
//	getline(is, v.tenPhim);        // Chú ý là is thay cho cin
//	do 
//	{
//		cout<<"Nhap gia tien:\n";
//		is>>v.giaTien;
//		if(v.giaTien < 0)
//			cout<<"Gia tien khong hop le. Nhap lai!\n";
//	}while(v.giaTien < 0);
//	is>>v.xuatChieu;            
//	is>>v.ngayXem;
//	return is;
//}
//ostream& operator<<(ostream& os, VE v)
//{
//	os<<endl<<"Ten phim: "<<v.tenPhim<<endl;
//	os<<"Gia tien: "<<v.giaTien<<endl;
//	os<<v.xuatChieu;          // Do đã nạp chồng toán tử << nên ta dùng cout<< xuất như bình thường 
//	os<<v.ngayXem; 
//	return os;
//};
//
//struct QUANLYVE
//{
//	VE* list;
//	int n;
//	VE& operator[](int index)         // Nạp chồng toán tử []. Kiến thức nâng cao      
//   {
//	return list[index];
//   }
//};
//
//void Nhapdanhsachve(QUANLYVE& QLV, int pn)
//{
//	QLV.list = new VE[pn];
//	QLV.n= pn;
//	for (int i = 0; i < QLV.n; i++)
//	{
//		cout<<"Nhap ve thu: "<<i+1<<endl;
//		cin>>QLV[i];             // Dùng QLV[i] thay vì QLV.list[i]. Công dụng của nạp chồng operator [] là vậy
//	}
//}
//void Xuatdanhsachve(QUANLYVE QLV)
//{
//	for (int i = 0; i < QLV.n; i++)
//	{
//		cout<<"Ve thu: "<<i+1<<endl;
//		cout<<QLV[i];              // Dùng QLV[i] thay vì QLV.list[i]. Công dụng của nạp chồng operator [] là vậy
//	}
//}
//
//unsigned int TinhTongGiaTien(QUANLYVE QLV)
//{
//	unsigned int tong = 0;
//	for(int i = 0; i  < QLV.n; i++)
//	{
//		tong += QLV[i].giaTien;
//	}
//	return tong;
//}
//// 2 hàm sau phục vụ cho hàm qsort C hỗ trợ sẵn. Các bạn có thể tự xây dựng hàm sắp xếp giá vé tăng dần.
//// Còn ở đây ad giới thiệu cách sử dụng hàm qsort của C. Thực hiện sort rất nhanh
//int SoSanhLonHon(const void* x, const void* y)
//{
//	if ( (*(VE*)x).giaTien > (*(VE*)y).giaTien)
//		return 1;
//	else if( (*(VE*)x).giaTien == (*(VE*)y).giaTien)
//		return 0;
//	else 
//		return -1;
//}
////int SoSanhNhoHon(const void* x, const void* y)
////{
////	if ( (*(VE*)x).giaTien < (*(VE*)y).giaTien)
////		return 1;
////	else if( (*(VE*)x).giaTien == (*(VE*)y).giaTien)
////		return 0;
////	else 
////		return -1;
////}
//
//int main()
//{
//	QUANLYVE QLV;
//	int soluong;
//	// Việc khởi tạo cho thành phần con trỏ list = NULL và biến n = 0 là 1 thói quen rất tốt 
//	QLV.list = NULL;
//	QLV.n = 0;
//	int chon;
//	do 
//	{
//		system("cls");                // Hàm xóa màn hình để menu thêm gọn
//		cout<<"0. Thoat\n\n";
//		cout<<"1. Nhap danh sach ve\n\n";
//		cout<<"2. Xuat danh sach ve\n\n";
//		cout<<"3. Tinh tong gia tien\n\n";
//		cout<<"4. Sap xep ve theo gia tien tang dan\n\n";
//		cout<<" Moi ban chon: ";
//		cin>>chon;
//		switch (chon)
//		{
//		case 0: break;
//		case 1: 
//			{
//				cout<<"Nhap so luong ve: ";
//				cin>>soluong;
//				Nhapdanhsachve(QLV, soluong);
//				break;
//			}
//		case 2:
//			{
//				Xuatdanhsachve(QLV);
//				system("pause");
//				break;
//			}
//		case 3:
//			{
//				unsigned int Tongtien = TinhTongGiaTien(QLV);
//				cout<<"Tong tien la "<<Tongtien;
//				system("pause");
//				break;
//			}
//		case 4:
//			{
//				qsort(QLV.list, QLV.n, sizeof(VE), SoSanhLonHon);
//				Xuatdanhsachve(QLV);
//				system("pause");
//				break;
//			}
//		} 
//	}while(chon != 0);
//	if(QLV.list != NULL)
//		delete []QLV.list;        // Thu hồi vùng nhớ HEAP do con trỏ list quản lý
//	return 0;
//}