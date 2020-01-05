#include "LIST.h"
#include "NODE.h"
#include "SINHVIEN.h"

//a. In danh sách sinh viên ra màn hình
//b. Liệt kê những sinh viên có điểm trung bình cao nhất trong lớp học.
//c. Cho biết số sinh viên có điểm trung bình >=5. Nếu không có thì thông báo không có.
//d. Tìm một sinh viên có tên X trong lớp học (X nhập từ bàn phím)
//e. Xoá một sinh viên có mã số cho trước trong lớp học. Nếu không có thì thông báo không có.
//f. Sắp xếp danh sách sinh viên tăng theo điểm trung bình bằng thuật toán sắp xếp mà các bạn đã học (Selection Sort, Interchange Sort, Binary Sort)
//g. Chèn một sinh viên vào lớp học, biết ràng sau khi chèn danh sách sinh viên vẫn tăng dần theo điểm trung bình.

int DemSVDiemTBLonHon5(LIST L)
{
	int dem = 0;
	for(NODE* p = L.GetHead(); p != NULL; p = p->GetNext())
	{
		if(p->GetData().GetDiemTB() >= 5)
			dem++;
	}
	return dem;
}
void LietKeSinhVienDiemTBMax(LIST L)
{
	NODE* pHead = L.GetHead();
	NODE* pTail = L.GetTail();
	float diemmax = pHead->GetData().GetDiemTB();
	for(NODE* p = pHead->GetNext(); p != NULL; p = p->GetNext())
	{
		float diem = p->GetData().GetDiemTB();
		if(diem > diemmax)
		{
			diemmax = diem;
		}
	}
	for(NODE* p = pHead; p != NULL; p = p->GetNext())
	{
		if(p->GetData().GetDiemTB() == diemmax)
		{
			p->GetData().Xuat();
		}
	}
}
void TimSinhVienX(LIST L,string hoten)
{
	NODE* p = L.SearchNode(hoten);
	if(p == NULL)
	{
		cout<<"Ko tim thay!\n";
	}
	else 
	{
		p->GetData().Xuat();
	}
}
void main()
{
	
	LIST L; // pHead = pTail = NULL;
	int chon;
	do 
	{
		system("cls");
		cout<<"0.Thoat\n\n";
		cout<<"1.Them Sinh Vien Vao Dau DS\n\n";
		cout<<"2.Them Sinh Vao Cuoi DS\n\n";
		cout<<"3.Xem Danh Sach\n\n";
		cout<<"4.Xem Nhung Sinh Vien Diem Cao Nhat\n\n";
		cout<<"5.Dem Sinh Vien DTB >= 5\n\n";
		cout<<"6.Tim Sinh Vien Theo Ho Ten\n\n";
		cout<<"Moi ban chon menu:\n";
		cin>>chon;
		switch (chon)
		{
		case 1:
			{
					SINHVIEN x;
				    x.Nhap();
				    L.AddHead(x);
				break;
			}
		case 2:
			{
				SINHVIEN x;
				x.Nhap();
				L.AddTail(x);
				break;
			}
		case 3:
			{
				L.Display();
				system("pause");
				break;
			}
		case 4:
			{
				LietKeSinhVienDiemTBMax(L);
					system("pause");
				break;
			}
		case 5:
			{
				int dem = DemSVDiemTBLonHon5(L);
				cout<<"So luong sinh vien thoa la "<<dem;
				system("pause");
				break;
			}
		case 6:
			{
				string hoten;
				fflush(stdin);
				cout<<"Nhap vao ho ten sinh vien muon tim:\n";
				getline(cin, hoten);
				TimSinhVienX(L, hoten);
                system("pause");
				break;
			}
		default:
			break;
		}
	}while(chon != 0);
}