#include <iostream>
#include <string>        // Include đến thư viện string của C++
using namespace std;

void BienHoaDauTu(string& s)
{
	if(s[0] >= 'a' && s[0] <= 'z')
	{
		s[0] -= 32;
	}
	for(int i = 1; i < s.length(); i++)
	{
		if(s[i-1] == ' ')
		{
			if(s[i] >= 'a' && s[i] <= 'z')
			{
				s[i] -= 32;
			}
		}
	}
}
void XoaKhoangTrangThua(string& s)
{
	for(int i = 0; i < s.length() - 1; i++)
	{
		if(s[i] == ' ' && s[i+1] == ' ')
		{
			s.erase(i, 1);
			i--;
		}
	}
	if(s[0] == ' ')
	{
		s.erase(0, 1);
	}
	if(s[s.length() - 1] == ' ')
	{
		s.erase(s.length() - 1, 1);
	}
}
int DemTu(string s)
{
	XoaKhoangTrangThua(s);
	int dem = 0;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == ' ')
		{
			dem++;
		}
	}
	return dem + 1;
}
int TimVitriTuChuaKyTuc(string s, char c)
{
	int dem = 0;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == ' ')
		{
			dem++;
		}
		if(s[i] == c)
		{
			return dem + 1;
		}
	}
	return -1;
}
int Demsolanxuathiencuakytu(string s, char c)
{
	int dem = 0;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == c)
			dem++;
	}
	return dem;
}
void TachHoTen(string s)
{
	int vitrikhoangtrangcuoi = (int)s.rfind(' ');
	string holot = s.substr(0, vitrikhoangtrangcuoi);
	string ten = s.substr(vitrikhoangtrangcuoi + 1, s.length() - (vitrikhoangtrangcuoi + 1));
	cout<<"Ho lot cua ban la: "<<holot<<endl;
	cout<<"Ten cua ban la: "<<ten<<endl;
}
//void DaoNguocThuTuTu(string s)
//{
//	XoaKhoangTrangThua(s);
//	int Sotu = DemTu(s);
//	string* MangTu = NULL;
//	MangTu = new string[Sotu + 1];
//	int dem = 0;
//	int start = 0;
//	int end = 0;
//	for(int i = 0; i < s.length(); i++)
//	{
//		if(s[i] == ' ')
//		{
//			end = i;
//			string Tu = s.substr(start, end - start);
//			MangTu[dem] = Tu;
//			dem++;
//			start  = end + 1;
//		}
//		if(i == s.length() - 1)
//		{
//			end = i;
//			string Tu = s.substr(start, end - start + 1);
//			MangTu[dem] = Tu;
//			dem++;
//			start  = end + 1;
//		}
//	}
//	for(int i = 0; i < dem / 2; i++)
//	{
//		string temp = MangTu[i];
//		MangTu[i] = MangTu[dem - 1 - i];
//		MangTu[dem  - 1 - i] = temp;
//	}
//	for(int i = 0; i < dem; i++)
//	{
//		cout<<MangTu[i]<<" ";
//	}
//	if(MangTu != NULL)
//		delete []MangTu;
//}
void DaoNguocThuTuTu2(string s)
{
	for(int i = s.length() - 1; i >= 0; i-- )
	{
		if(s[i] == ' ' || i == 0)
		{
			int j;
			if(i == 0)
			j = i;
			else
			j = i + 1;
			for( ; s[j] != ' ' && s[j] != NULL; j++)
			{
				cout<<s[j];
			}
			cout<<" ";
		}
	}
}
bool KiemTraTrung(string s, int vitrikiemtra)
{
	for(int i = 0; i < vitrikiemtra; i++)
	{
		if(s[i] == s[vitrikiemtra])
			return true;
	}
	return false;
}
void LietKeTanSuatcuaMoiKyTu(string s)
{
	for(int i = 0; i < s.length(); i++)
	{
		if(KiemTraTrung(s, i))
		{
			continue;
		}
		else 
			cout<<"Ky tu "<<s[i]<<" xuat hien "<<Demsolanxuathiencuakytu(s, s[i])<<endl;
	}
}
int main()
{
	string s = "";
	int chon;
	do 
	{
		system("cls");
		cout<<"0. Thoat\n\n";
		cout<<"1. Nhap chuoi\n\n";
		cout<<"2. Xuat chuoi\n\n";
		cout<<"3. Xoa Khoang Trang Thua\n\n";
		cout<<"4. Bien Hoa Dau Tu\n\n";
		cout<<"5. Dem Tu\n\n";
		cout<<"6. Doi chuoi sang so nguyen\n\n";
		cout<<"7. Tim vi tri cua tu chua ky tu c\n\n";
		cout<<"8. Tach Ho Ten Thanh Ho lot va ten\n\n";
		cout<<"9. Dao Nguoc Thu Tu Cac Tu\n\n";
		cout<<"10.Liet Ke Tan Suat Moi Ky Tu\n\n";
		cout<<"Moi ban chon menu:\n";
		cin>>chon;
		switch (chon)
		{
		case 0:break;
		case 1:
			{
				fflush(stdin);
				cout<<"Nhap chuoi:\n";
				getline(cin, s);
				break;
			}
		case 2:
			{
				cout<<s;
				system("pause");
				break;
			}
		case 3:
			{
				XoaKhoangTrangThua(s);
				cout<<s;
				system("pause");
				break;
			}
		case 4:
			{
				BienHoaDauTu(s);
				cout<<s;
				system("pause");
				break;
			}
		case 5:
			{
				int Sotu = DemTu(s);
				cout<<"So tu la "<<Sotu;
				system("pause");
				break;
			}
		case 6:
			{
				int x = atoi(s.c_str());
				if(x > 0)
					cout<<x<<" la so duong\n";
				if(x < 0)
					cout<<x<<" la so am\n";
				system("pause");
				break;
			}
		case 7:
			{
				char c;
				cout<<"Nhap ky tu muon tim:\n";
				cin>>c;
				if((int)s.find(c) != -1)
				{
					cout<<"Ky tu "<<c<<" nam trong tu thu "<<TimVitriTuChuaKyTuc(s, c);
				}
				else 
				{
					cout<<"Ko tim thay ky tu "<<c<<" trong chuoi\n";
				}
				system("pause");
				break;
			}
		case 8:
			{
				TachHoTen(s);
				system("pause");
				break;
			}
		case 9:
			{
				DaoNguocThuTuTu2(s);
				system("pause");
				break;
			}
		case 10:
			{
				LietKeTanSuatcuaMoiKyTu(s);
				system("pause");
				break;
			}
		default:
			break;
		}
	}while(chon != 0);
	cin.get();
	return 0;
}