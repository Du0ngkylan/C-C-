//
//2/Viết CT thực hiện những yêu cầu sau:
//a.Nhập mảng 1 chiều các luận văn (LUANVAN). Biết rằng 1 luận văn gồm các thông tin sau:
//- Mã luận văn: kiểu string
//- Tên luận văn: kiểu string
//- Họ tên sinh viên: kiểu string
//- Họ tên  giáo viên hướng dẫn: kiểu string
//- Ngày thực hiện: kiểu NGAY
//b. Xuất mảng
//c. Tìm  năm có nhiều luận văn nhất
//d. Liệt kê các luận văn thực hiện gần nhất.
#include <iostream>
#include <string>
#include <vector>        // Thư viện nằm trong bộ 32 thư viện STL của C++. Thu vien vector hỗ trợ tạo lập mảng động
using namespace std;

class NGAY 
{
private:
	short ngay;
	short thang;
	short nam;
public:
	short Getnam();
	friend istream& operator>>(istream& is ,NGAY &x )
	{
		cout<<"Nhap ngay, thang, nam:\n";
		is>>x.ngay>>x.thang>>x.nam;
		return is;
	}
	friend ostream& operator<<(ostream& os,NGAY x)
	{
		os<<x.ngay<<"/"<<x.thang<<"/"<<x.nam<<endl;
		return os;
	}
	NGAY()
	{
		ngay = 1;
		thang = 1;
		nam = 1990;
	}
};
short NGAY::Getnam()
{
	return this->nam;
}
class LUANVAN 
{
private:
	string Maluanvan, Tenluanvan;
	string HoTensv, HoTengv;
	NGAY Ngaythuchien;
public:
	NGAY Getngaythuchien();
	LUANVAN()
	{
		Maluanvan = Tenluanvan = HoTengv = HoTensv = "Chua co";
	}
	LUANVAN(string Maluanvan,string Tenluanvan,string HoTensv,string HoTengv,NGAY Ngaythuchien)
	{
		this->Maluanvan = Maluanvan;
		this->Tenluanvan = Tenluanvan;
		this->HoTensv = HoTensv;
		this->HoTengv = HoTengv;
		this->Ngaythuchien = Ngaythuchien;
	}
	friend istream& operator>>(istream& is ,LUANVAN &x )
	{
		fflush(stdin);
		cout<<endl<<"Nhap Ma luan van:\n";
		getline(is, x.Maluanvan);
		cout<<"Nhap Ten luan van:\n";
		getline(is, x.Tenluanvan);
		cout<<"Nhap ho ten sv:\n";
		getline(is, x.HoTensv);
		cout<<"Nhap ho ten giao vien:\n";
		getline(is, x.HoTengv);
		is>>x.Ngaythuchien;
		return is;
	}
	friend ostream& operator<<(ostream& os,LUANVAN x)
	{
		os<<endl<<"Ma luan van: "<<x.Maluanvan<<endl;
		
		os<<"Ten luan van: "<<x.Tenluanvan<<endl;
		
		os<<"Ho ten sv: "<<x.HoTensv<<endl;
		
		os<<"Ho ten giao vien: "<<x.HoTengv<<endl;
		os<<x.Ngaythuchien;
		return os;
	}
};
NGAY LUANVAN::Getngaythuchien()
{
	return this->Ngaythuchien;
}
class QUANLYLUANVAN 
{
private:
	vector<LUANVAN>  list;
   
	int SoLuanVanTrongNamx(short x)
	{
		int dem = 0;
		for(int i = 0; i < list.size(); i++)
		{
			if(list[i].Getngaythuchien().Getnam() == x)
				dem++;
		}
		return dem;
	}
public:
	vector<LUANVAN>& Getlist();
	short NamNhieuLuanVanNhat();
	void LKLuanVanThucHienGanNhat();
	QUANLYLUANVAN()
	{
		list.resize(0);    // 
	}
	~QUANLYLUANVAN()  // Hàm hủy
	{
		list.clear();
	}
};
vector<LUANVAN>& QUANLYLUANVAN::Getlist()
{
	return this->list;
}
short  QUANLYLUANVAN::NamNhieuLuanVanNhat()
{
	int nammax = list[0].Getngaythuchien().Getnam();
	int soluanvanmax  = this->SoLuanVanTrongNamx(nammax);
	for(int i = 1; i < list.size(); i++)
	{
		if(SoLuanVanTrongNamx(list[i].Getngaythuchien().Getnam()) > soluanvanmax)
		{
				soluanvanmax = SoLuanVanTrongNamx(list[i].Getngaythuchien().Getnam());
				nammax = list[i].Getngaythuchien().Getnam();
		}
		return nammax;
	}
}

void QUANLYLUANVAN::LKLuanVanThucHienGanNhat()
{
	int namgannhat = list[0].Getngaythuchien().Getnam();
	for(int i = 1; i < list.size(); i++)
	{
		if(list[i].Getngaythuchien().Getnam() > namgannhat)
			namgannhat = list[i].Getngaythuchien().Getnam();
	}

	for(int i = 0; i < list.size(); i++)
	{
		if(list[i].Getngaythuchien().Getnam() == namgannhat)
			cout<<list[i];
	}
}

int main()
{
	int chon;
	QUANLYLUANVAN* ql = new QUANLYLUANVAN();
	system("color f");
	do 
	{
		system("cls");
		cout<<"1.Them Luan Van Vao Danh Sach\n\n";
		cout<<"2.Xuat Danh Sach Luan Van\n\n";
		cout<<"3.Tim Nam Thuc Hien Nhieu Luan Van Nhat\n\n";
		cout<<"4.Liet Ke Cac Luan Van Thuc Hien Gan Nhat\n\n";
		cout<<"5.Thoat\n";
		cout<<"Moi ban chon menu:\n";
		cin>>chon;
		switch (chon)
		{
		case 1:
			{
				LUANVAN x;
				cin>>x;
				cout<<x;
				ql->Getlist().push_back(x);
				break;
			}
		case 2:
			{
				for(int i = 0; i < ql->Getlist().size(); i++)
				{
					cout<<ql->Getlist().at(i);
				}
				system("pause");
				break;
			}
		case 3:
			{
				cout<<"Nam thuc hien nhieu luan van nhat la "<<ql->NamNhieuLuanVanNhat();
				system("pause");
				break;
			}
		case 4:
			{
				ql->LKLuanVanThucHienGanNhat();
				system("pause");
				break;
			}
		default:
			break;
		}
	}while(chon != 5);
	delete ql;
}



