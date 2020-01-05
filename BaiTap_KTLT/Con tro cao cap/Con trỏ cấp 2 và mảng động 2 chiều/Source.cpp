#include <iostream>
using namespace std;

void CapPhat(int**& a, int sodong,int socot)
{
	a = new int* [sodong];
	for(int i = 0; i < sodong; i++)
	{
		a[i] = new int[socot];
	}
}
void ThuHoi(int**& a, int sodong)
{
	for(int i = 0; i < sodong; i++)
	{
		delete [] a[i];
	}
	delete []a;
}
void NhapMaTran(int** a, int sodong, int socot)
{
	for(int i = 0; i < sodong * socot; i++)
	{
		cout<<"Nhap vao a["<<i / socot<<"]["<<i % socot<<"]:\n";
		cin>>a[i / socot][i % socot];
	}
}

void XuatMaTran(int** a, int sodong, int socot)
{
	for(int i = 0; i < sodong * socot; i++)
	{
		cout<<a[i / socot][i % socot]<<"\t";
		if((i + 1) % socot == 0)
			cout<<endl;
	}
}

int main()
{
	int sodong, socot;
	do 
	{
		cout<<"Nhap so dong, so cot:\n";
		cin>>sodong>>socot;
		if(sodong < 0 || socot < 0)
			cout<<"Du lieu khong hop le. Nhap lai!\n";
	}while(sodong < 0 || socot < 0);

	int** a = NULL;
	CapPhat(a, sodong, socot);

	NhapMaTran(a, sodong, socot);
	XuatMaTran(a, sodong, socot);
	if(a != NULL)
	{
		ThuHoi(a, sodong);
	}

	system("pause");
	return 0;
}
