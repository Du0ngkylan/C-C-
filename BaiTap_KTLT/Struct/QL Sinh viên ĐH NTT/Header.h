#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct SINHVIEN
{
	string HoTen;
	string MSSV;
	float DiemTrungBinh;
};

void NhapSV(SINHVIEN& sv)
{
	fflush(stdin);
	cout << "Nhap vao ho va ten sinh vien\n";
	getline(cin, sv.HoTen);
	cout << "Nhap vao MSSV\n";
	getline(cin, sv.MSSV);
	do 
	{
	cout << "Nhap vao diem trung binh cua sinh vien";
	cin >> sv.DiemTrungBinh;
	if(sv.DiemTrungBinh < 0 || sv.DiemTrungBinh > 10)
		cout<<"Diem trung binh khong hop le. Nhap lai!\n";
	}while(sv.DiemTrungBinh < 0 || sv.DiemTrungBinh > 10);
}
void XuatSV(const SINHVIEN sv)
{
	cout <<"Ho va ten: "<< sv.HoTen << endl;
	cout <<"Ma so sinh vien: "<<sv.MSSV << endl;
	cout <<"Diem trung binh mon: "<<sv.DiemTrungBinh << endl;
}

void NhapDanhSach(vector<SINHVIEN>& list)
{
	SINHVIEN sv;
	NhapSV(sv);
	list.push_back(sv);
}

void XuatDanhSach(vector<SINHVIEN> list)
{
	for (int i = 0; i < list.size(); i++)
	{
		XuatSV(list[i]);
		cout << endl;
	}
}
void LietKeDiemCao(vector<SINHVIEN> list)
{
	float max = list[0].DiemTrungBinh;
	for (int i = 1; i < list.size(); i++)
	{
		if (list[i].DiemTrungBinh > max)
			max = list[i].DiemTrungBinh;
	}

	cout << "Sinh vien co diem trung binh cao nhat la:\n";
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].DiemTrungBinh == max)
			XuatSV(list[i]);
		cout << endl;
	}
}
int SoSVDTBLonHonHoacBang5(vector<SINHVIEN> list)
{
	int dem = 0;
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].DiemTrungBinh >= 5)
		{
			dem = dem + 1;
		}
	}
	return dem;
}
void InterchangeSort(vector<SINHVIEN>& list)
{
	for (int i = 0; i < list.size() - 1; i++)
	{
		for (int j = i + 1; j < list.size(); j++)
		{
			if (list[i].DiemTrungBinh > list[j].DiemTrungBinh)
			{
				swap(list[i], list[j]);
			}
		}
	}
}

void ChenSVGiuNguyenDSTang(vector<SINHVIEN>& list, SINHVIEN sv)
{
	if(sv.DiemTrungBinh <= list[0].DiemTrungBinh)
	{
		list.insert(list.begin(), sv);
		return;
	}
	if(sv.DiemTrungBinh >= list[list.size() - 1].DiemTrungBinh)
	{
		list.push_back(sv);
		return;
	}
	for(int i = 0; i < list.size() - 1; i++)
	{
		if(sv.DiemTrungBinh >= list[i].DiemTrungBinh && sv.DiemTrungBinh <= list[i+1].DiemTrungBinh)
		{
			list.insert(list.begin() + ( i + 1), sv);
			break;
		}
	}
}