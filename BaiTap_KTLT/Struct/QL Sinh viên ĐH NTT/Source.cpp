#include "Header.h"

int main()
{
	vector<SINHVIEN> list;
	int chon;
	do
	{
		fflush(stdin);
		system("cls");
		cout << "0.Thoat.\n\n";
		cout << "1.Nhap thong tin sinh vien.\n\n";
		cout << "2.Xuat thong tin sinh vien.\n\n";
		cout << "3.Liet ke nhung sinh vien co diem cao nhat.\n\n";
		cout << "4.Dem so sinh vien co DTB lon hon 5.\n\n";
		cout << "5.Sap xep sinh vien co diem trung binh tang dan.\n\n";
		cout << "6.Chen sinh vien vao sao cho danh sach van giu nguyen diem tang dan\n\n";
		cout << "7.Xoa Sinh Vien Co Ma So Cho Truoc\n\n";
		cout << "Moi ban chon menu:\n\n";
		cin >> chon;
		switch (chon)
		{
			case 1:
			{
					  NhapDanhSach(list);
					  break;
			}
			case 2:
			{
					  XuatDanhSach(list);
					  system("pause");
					  break;
			}
			case 3:
			{
					  LietKeDiemCao(list);
					  system("pause");
					  break;
			}
			case 4:
			{
					  int dem = SoSVDTBLonHonHoacBang5(list);
					  if (dem > 0)
						  cout << "Co " << dem << " sinh vien co DTB>=5\n";
					  else
						  cout << "Khong co sinh vien nao DTB>=5.\n";
					  system("pause");
					  break;
			}
			case 5:
			{
					  InterchangeSort(list);
					  XuatDanhSach(list);
					  system("pause");
					  break;
			}
			case 6:
			{
				cout<<"Nhap sinh vien muon chen\n\n";
				SINHVIEN sv;
				NhapSV(sv);
				ChenSVGiuNguyenDSTang(list, sv);
				break;
			}
			case 7:
			{
					string MSSV;
					fflush(stdin);
					cout<<"Nhap MSSV muon xoa:\n";
					getline(cin, MSSV);
					for(int i = 0; i < list.size(); i++)
					{
						if(list[i].MSSV == MSSV)
						{
							list.erase(list.begin() + i);
							break;
						}
					}
					XuatDanhSach(list);
					system("pause");
					break;
			}
		}

	} while (chon != 0);
}