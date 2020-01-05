#include "Strangle.h"
#include < vector >
int main()
{
	STRANGLE ST;
	NhapCacDinh(ST);
	XuatCacDinh(ST);
	int * p;
	POINT G = TimTrongTam(ST);
	cout<<endl<<"Trong Tam G: ";
	XuatDiem(G);

	float CV = TinhChuVi(ST);
	float DT = TinhDienTich(ST);
	cout<<endl<<"Chu vi tam giac: "<<CV<<endl;
	cout<<"Dien tich tam giac: "<<DT<<endl;
	XuatDinhGanToaDoNhat(ST);
	system("pause");
	return 0;
}